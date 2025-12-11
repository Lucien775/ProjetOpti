#ifndef DEMARRAGE
#define DEMARRAGE 

#include "../Evenement.h"

template <size_t N>
class EvenementDemarrage : public Evenement<N>
{
	std::string nomAlgo;
	Vecteur<N> x0;
	FonctionObjectif f;
	int max_iter;
public:
	EvenementDemarrage(const std::string& nomAlgo, const Vecteur<N> x0, const FunctionObjectif<N>& f, int max_iter)
		: nomAlgo(nomAlgo), x0(x0), f(f), max_iter(max_iter) {}
};


#endif