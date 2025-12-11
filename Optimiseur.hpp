#ifndef ALGO
#define ALGO 
#include <stdlib.h>
#include <vector>
#include "Pas.hpp"
#include "io/evenement/Demarrage.hpp"
#include "io/evenement/Demarrage.hpp"
#include "io/evenement/EvenementIteration.hpp"
#include "io/evenement/EvenementIteration.hpp"
#include "io/evenement/EvenementTerminaision.hpp"
#include "io/observateur/LoggerConsole.hpp"



template <size_t N>
class Optimiseur
{
protected: 

    FonctionObjectif<N>& f;
    PasDeplacement<N>& Pas;
    double epsilon;
    int max_iters;

    std::vector<Observateur<N>*> observateurs;

public:
    Optimiseur(FonctionObjectif<N>& func, PasDeplacement<N>& Pas, double e, int max_it)
        : f(func), Pas(Pas), epsilon(e), max_iters(max_it) {}

    virtual ~Optimiseur() = default;
    virtual std::string getNom() const = 0;

    void ajouterObservateur(Observateur<N>* obs)
    {
        observateurs.push_back(obs);
    }

    void notifier(const Evenement<N>& event)
    {
        for (auto* obs : observateurs)
            obs->onNotify(event);
    }

    void optimiser(Vecteur<N>& x_depart)
    {
        notifier(EvenementDemarrage<N>(this->getNom() ,x_depart, f, max_iters));

        auto x = x_depart;

        for (int k = 0; k <= max_iters; ++k)
        {
            double fx = f.evaluer(x);
            auto grad = f.calculerGradient(x);
            double grad_norm = grad.calculNorm();

            notifier(EvenementIteration<N>(k, grad_norm, fx, x));

            if (grad_norm < epsilon)
            {
                notifier(EvenementTerminaison<N>(x, fx, true));
                return;
            }

            auto d = calculerDirection(x);

            x = x + d * Pas.getPas();
        }
        notifier(EvenementTerminaison<N>(x, f.evaluer(x), false));
    }
    virtual Vecteur<N> calculerDirection(const Vecteur<N>& x) const = 0;
};



template <size_t N>
class DescenteGradient : public Optimiseur<N>
{
public:
    DescenteGradient(FonctionObjectif<N>& func, PasDeplacement<N>& Pas,double e, int max_it)
        : Optimiseur<N>(func, Pas , e, max_it) {}

    ~DescenteGradient() override = default;
    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override
    {
        auto g = this->f.calculerGradient(x);
        return g * (-1.0);   
    }

    std::string getNom() const override {
        return "méthode descente de gradient pas fixe";
    }
};

template <size_t N>
class PlusFortePente : public Optimiseur<N>
{
public:
    PlusFortePente(FonctionObjectif<N>& func, PasDeplacement<N>& Pas ,double e, int max_it)
        : Optimiseur<N>(func, Pas ,e, max_it) {}

    ~PlusFortePente() override = default;
    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override
    {
        auto g = this->f.calculerGradient(x);
        double g_norm = g.calculNorm();
        double coeff = (-1.0) / g_norm;
        return g * coeff;   
    }

    std::string getNom() const override {
        return "méthode de la plus forte pente";
    }
};


#endif

