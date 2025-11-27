#include <stdlib.h>
#include "descente.cpp"

class Algorithme
{
private:
	IFonction& f;
	DirDescenteRealisable directionMethod;
	double alpha;
	double epsilon;
public:
	Algorithme(IFonction& func,DirDescenteRealisable dir,double a,double e): 
		f(func), directionMethod(dir), alpha(a), epsilon(e) {}

	std::vector<double> minimize(std::vector<double>x0) 
	{
		std::vector<double> x = x0;
		while (norm(f.gradient(x)) > epsilon)
		{
			std::vector<double> d = directionMethod.Direction(x, f);
			double lambda = alpha;

			for (size_t i = 0; i < x.size(); ++i)
			{
				x[i] += lambda * d[i];
			}
		}
		return x;
	}
private:
	static double norm(const std::vector<double>& v)
	{
		double sum = 0.0;
		for (double x : v)
			sum += x*x;

		return std::sqrt(sum);
	}
};

int main(){

    Fonction1 f1;
    Fonction2 f2;
    Fonction3 f3;

    double alpha = 0.1;
    double epsilon = 10e-6;
    vector<double> x_init(0.0,0.0);


    DirDescenteRealisable d;

    Algorithme algo(f1, d, alpha, epsilon);

    vector<double> res = algo.minimize(x_init);

    cout << "Résultat de la minimisation de la fonction 1 : " << endl;
    for (double i : res)
    	cout << i << endl;



    return 0;
}
