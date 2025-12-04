/*#include <iostream>
#include <vector>
#include "Algorithme.cpp"

class Logger
{
public:
	Logger() = default;
	~Logger() = default;

	void start(const std::vector<double>& x0, const FonctionObjectif&, const Optimiseur& dir)
	{
		std::cout << "---\n--- Descente de Gradient (Pas Fixe)\n---" << std::endl;
		std::cout << "\nPoint initial : (";
		for (size_t i = 0; i < x0.size() - 1; ++i)
			std::cout << x0[i] << ", ";
		std::cout << x0[x0.size() - 1] << ")\n" << std::endl;

		std::cout << "Méthode : Descente de Gradient" << std::endl;

		cout << "Max-iters : 100\n" << std::endl;
        cout << "Iter.    Obj.        ||Grad||     Point" << std::endl;
	}

	void log(size_t k, double fx, double grad, const std::vector<double>& x)
	{
		if (k % 10 == 0)
		{
			std::cout << k << "    ";
			std::cout.precision(5);
			std::cout << fx << "    ";
			std::cout << scientific << grad << "    ";

			std::cout << "(";
            std::cout.precision(2);
            for (size_t i = 0; i < x.size(); i++)
                std::cout << x[i] << (i + 1 < x.size() ? ", " : "");
            std::cout << ")" << std::endl;
		}
	}

	void end(const std::vector<double>& x_final, double f_final, bool converged)
	{
        std::cout << "Solution :\n";

        if (converged)
            std::cout << "Statut : CONVERGENCE (Tolérance atteinte)\n";
        else
            std::cout << "Statut : MAX ITERATIONS ATTEINTES\n";

        std::cout << "Solution : (";
        for (size_t i = 0; i < x_final.size() - 1; i++)
            std::cout << x_final[i]<< ", ";
        std::cout << x_final[x_final.size() - 1];
        std::cout << ")\n";

        std::cout << "Valeur : " << f_final << endl;
    }
};*/