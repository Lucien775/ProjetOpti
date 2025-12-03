#include <stdlib.h>
#include "Logger.cpp"

class Algorithme
{
private:
	IFonction& f;
	DirDescenteRealisable directionMethod;
	double alpha;
	double epsilon;
	int max_iters;
public:
	Algorithme(IFonction& func, DirDescenteRealisable dir, double a, double e, int max_iters): 
		f(func), directionMethod(dir), alpha(a), epsilon(e), max_iters(max_iters) {}

	void minimize(std::vector<double>x0) 
	{
		Logger logger;
		logger.start(x0, f, directionMethod);

		auto x = x0;
		for (size_t k = 0; k <= max_iters; ++k)
		{
			double fx = f.result(x);

			double grad_norm = 0.0;
			for (double v : f.gradient(x)) 
				grad_norm += v*v;
			grad_norm = sqrt(grad_norm);

			logger.log(k, fx, grad_norm, x);

			if (grad_norm < epsilon)
			{
				logger.end(x, fx, true);
				return;
			}

			auto d = directionMethod.Direction(x, f);
			for (size_t i = 0; i < x.size(); ++i)
			{
				x[i] += alpha * d[i];
			}
		}
		logger.end(x, f.result(x), false);
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
    x_init = {1.0, 1.0};
    Algorithme algo3(f3, dir3, alpha, epsilon, 100);
    algo3.minimize(x_init);

    return 0;
}
