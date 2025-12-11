#ifndef LOGGER
#define LOGGER 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include "function.hpp"
//#include "Optimiseur.hpp"


template <size_t N>
class Logger
{
public:
	Logger() = default;
	~Logger() = default;

	void start(const std::string nomAlgo, const Vecteur<N>& x0, const FonctionObjectif<N>& f, int max_iter) const
	{
		std::cout << "---\n---" <<  nomAlgo <<"\n---" << std::endl;

		std::cout << "\nPoint initial : (";
		for (size_t i = 0; i < x0.size() - 1; ++i)
			std::cout << x0[i] << ", ";
		std::cout << x0[x0.size() - 1] << ")\n" << std::endl;

		std::cout << "Fonction : " << std::endl;
		f.afficher_f();

		std::cout << "Méthode : " << nomAlgo << std::endl;

		std::cout << "Max-iters : 100\n" << std::endl;
        std::cout << "Iter.    Obj.        ||Grad||     Point" << std::endl;
	}

	void log(int k, double fx, double grad_norm, const Vecteur<N>& x) const
	{
		if (k % 10 == 0)
		{
			std::cout << k << "    ";
			std::cout << setprecision(5)<< fixed << fx << "    ";
			std::cout << setprecision(2)<< scientific << grad_norm << "    ";

			std::cout << "(";
            for (size_t i = 0; i < x.size(); i++)
                std::cout << setprecision(2) << fixed <<x[i] << (i + 1 < x.size() ? ", " : "");
            std::cout << ")" << std::endl;
		}
	}

	void end(const Vecteur<N>& x_final, double f_final, bool converged) const
	{
        std::cout << "Solution :\n";

        if (converged)
            std::cout << "Statut : CONVERGENCE (Tolérance atteinte)\n";
        else
            std::cout << "Statut : MAX ITERATIONS ATTEINTES\n";

        std::cout << "Solution : (";
        for (size_t i = 0; i < x_final.size() - 1; i++)
            std::cout << setprecision(2) << fixed << x_final[i]<< ", ";
        std::cout << setprecision(2) << fixed << x_final[x_final.size() - 1];
        std::cout << ")\n";

        std::cout << "Valeur : " << setprecision(2) << fixed << f_final << endl;
    }
};


#endif
