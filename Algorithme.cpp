#include <stdlib.h>

class Algorithme
{
private:
	IFunction& f;
	DirDescenteRealisable directionMethod;
	double alpha;
	double epsilon;
public:
	Algorithme(IFunction& func,DirDescenteRealisable dir,double a,double e): 
		f(func), directionMethod(dir), alpha(a), epsilon(e) {}

	std::vector<double> minimize(std::vector<double>x0) const
	{
		std::vector<double> x = x0;
		while (norm(f.gradient(x)) > epsilon)
		{
			std::vector<char> d = directionMethod.Direction();
			double lambda = alpha;

			for (size_t i = 0; i < x.size; ++i)
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
