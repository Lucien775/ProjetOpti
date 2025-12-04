#ifndef ALGO
#define ALGO 

#include <stdlib.h>
#include "Logger.cpp"

template <size_t N>
class Optimiseur
{
protected: 
    FonctionObjectif<N>& f;
    double alpha;
    double epsilon;
    int max_iters;

public:
    Optimiseur(FonctionObjectif<N>& func, double a, double e, int max_it)
        : f(func), alpha(a), epsilon(e), max_iters(max_it) {}

    virtual ~Optimiseur() = default;
    void optimiser(Vecteur<N>& x_depart)
    {
        Logger<N> logger;
        logger.start(*this, x_depart, f, max_iters);

        auto x = x_depart;

        for (int k = 0; k <= max_iters; ++k)
        {
            double fx = f.evaluer(x);

            auto grad = f.calculerGradient(x);
            double grad_norm = grad.calculNorm();

            logger.log(k, fx, grad_norm, x);

            if (grad_norm < epsilon)
            {
                logger.end(x, fx, true);
                return;
            }

            auto d = calculerDirection(x);

            x = x + d * alpha;
        }
        logger.end(x, f.evaluer(x), false);
    }
    virtual Vecteur<N> calculerDirection(const Vecteur<N>& x) const = 0;
    virtual void afficher() const = 0;
};



template <size_t N>
class DescenteGradient : public Optimiseur<N>
{
public:
    DescenteGradient(FonctionObjectif<N>& func, double a, double e, int max_it)
        : Optimiseur<N>(func, a, e, max_it) {}

    ~DescenteGradient() override = default;
    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override
    {
        auto g = this->f.calculerGradient(x);
        return g * (-1.0);   
    }

    void afficher() const
    {
        std::cout << "Descente de Gradient (Pas Fixe)" << std::endl;
    }
};

template <size_t N>
class PlusFortePente : public Optimiseur<N>
{
public:
    PlusFortePente(FonctionObjectif<N>& func, double a, double e, int max_it)
        : Optimiseur<N>(func, a, e, max_it) {}

    ~PlusFortePente() override = default;
    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override
    {
        auto g = this->f.calculerGradient(x);
        double g_norm = g.calculNorm();
        double coeff = (-1.0) / g_norm;
        return g * coeff;   
    }

    void afficher() const
    {
        std::cout << "Plus forte pente" << std::endl;
    }
};


int main(){
    /*Paramètre généraux*/
    double alpha = 0.1;
    double epsilon = 10e-6;
    
    FonctionObjectif1 f1;
    DescenteGradient<2> dg(f1, alpha, epsilon, 100);
    Vecteur<2> x0 = {0.0, 0.0};
    dg.optimiser(x0);
    

    return 0;
}


#endif

