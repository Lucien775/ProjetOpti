#include <stdlib.h>
#include "Logger.cpp"
#include "Vecteur.cpp"



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
	template <size_t N>
    void optimiser(Vecteur& x_depart)
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

            for (size_t i = 0; i < x.getDim(); ++i)
                x[i] += alpha * d[i];
        }
    }
	template <site_t N>
    virtual Vecteur calculerDirection(const Vecteur& x) const = 0;
};



template <size_t N>
class DescenteGradient : public Optimiseur
{
public:
	template <size_t N>
    DescenteGradient(FonctionObjective& func, double a, double e, int max_it)
        : Optimiseur(func, a, e, max_it) {}

    ~DescenteGradient() override = default;
	template <size_t N>
    Vecteur calculerDirection(const Vecteur& x) const override
    {
        auto g = f.calculerGradient(x);
        return g * (-1.0);   
    }
};

template <size_t N>
class PlusFortePente : public Optimiseur
{
public:
	template <size_t N>
    PlusFortePente(FonctionObjective& func, double a, double e, int max_it)
        : Optimiseur(func, a, e, max_it) {}

    ~PlusFortePente() override = default;
	template <size_t N>
    Vecteur calculerDirection(const Vecteur& x) const override
    {
        auto g = f.calculerGradient(x);
        double g_norm = g.norm();
        return (g * (-1.0))/g_norm;   
    }
    
};


int main(){
	/*Paramètre généraux*/
	double alpha = 0.1;
    double epsilon = 10e-6;
	
	
    /*Test sur la fonction 1*/
    std::cout << "\n\n------ Test sur f1 ------" << std::endl;
    Fonction1 f1;
    DirDescenteRealisable dir1;
    std::vector<double> x_init = {3.0, 5.0};
    Algorithme algo1(f1, dir1, alpha, epsilon, 100);
    algo1.minimize(x_init);
	
    /*Test sur la fonction 1*/
    std::cout << "\n\n------ Test sur f2 ------" << std::endl;
    Fonction2 f2;
	DirDescenteRealisable dir2;
    x_init = {3.0, 5.0, 2.0};
    Algorithme algo2(f2, dir2, alpha, epsilon, 100);
    algo2.minimize(x_init);
	
    /*Test sur la fonction 3*/
    std::cout << "\n\n------ Test sur f3 ------" << std::endl;
    Fonction1 f3;
	DirDescenteRealisable dir3;
    x_init = {0.0, 0.0};
    Algorithme algo3(f3, dir3, alpha, epsilon, 100);
    algo3.minimize(x_init);

    return 0;
}
