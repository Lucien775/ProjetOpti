#include <stdlib.h>
#include "Logger.cpp"

class Optimiseur
{
private:
	FonctionObjective& f;
	double alpha;
	double epsilon;
	int max_iters;
public:
	Optimiseur(FonctionObjective& func, double a, double e, int max_iters):
		f(func), alpha(a), epsilon(e), max_iters(max_iters) {}

	~Optimiseur() = default;

	void optimiser(Vecteur& x_depart)
	{
		auto x = x_depart;
		for (size_t k = 0; k <= max_iters; ++k)
		{
			double fx = f.evaluer(x);

			auto grad = f.calculerGradient(x);
			double grad_norm = grad.norm();

			if (grad_norm < epsilon)
			{
				return;
			}

			auto d = calulerDirection(x);
			for (size_t i = 0; i < d.getDim(); ++i)
			{
				x[i] += alpha * d[i];
			}

		}
	}

	Vecteur calculerGradient(const Vecteur& x) const = 0;
	
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
