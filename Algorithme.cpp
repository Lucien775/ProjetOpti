#include <stdlib.h>
#include "function.cpp"



template <size_t N>
class Optimiseur
{
protected: 
    FonctionObjective& f;
    double alpha;
    double epsilon;
    int max_iters;

public:
    Optimiseur(FonctionObjective& func, double a, double e, int max_it)
        : f(func), alpha(a), epsilon(e), max_iters(max_it) {}

    virtual ~Optimiseur() = default;
    void optimiser(Vecteur<N>& x_depart)
    {
        auto x = x_depart;

        for (int k = 0; k <= max_iters; ++k)
        {
            double fx = f.evaluer(x);

            auto grad = f.calculerGradient(x);
            double grad_norm = grad.norm();

            if (grad_norm < epsilon)
            {
                x_depart = x;
                return;
            }

            auto d = calculerDirection(x);

            x = x + d*alpha;
        }
    }
    virtual Vecteur<N> calculerDirection(const Vecteur<N>& x) const = 0;
};



template <size_t N>
class DescenteGradient : public Optimiseur
{
public:
    DescenteGradient(FonctionObjective& func, double a, double e, int max_it)
        : Optimiseur(func, a, e, max_it) {}

    ~DescenteGradient() override = default;
    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override
    {
        auto g = f.calculerGradient(x);
        return g * (-1.0);   
    }
};

template <size_t N>
class PlusFortePente : public Optimiseur
{
public:
    PlusFortePente(FonctionObjective& func, double a, double e, int max_it)
        : Optimiseur(func, a, e, max_it) {}

    ~PlusFortePente() override = default;
    Vecteur<N> calculerDirection(const Vecteur<N>& x) const override
    {
        auto g = f.calculerGradient(x);
        double g_norm = g.norm();
        double coeff = (-1.0) / g_norm;
        return g * coeff;   
    }
};


int main(){
	/*Paramètre généraux*/
	double alpha = 0.1;
    double epsilon = 10e-6;
	
    FonctionObjective f1;
	DescenteGradient dg(f1, alpha, epsilon, 100);
    Vecteur x0 = {0.0, 0.0}
	DescenteGradient.optimiser(x0);
    

    return 0;
}
