#ifndef ITTERATION
#define ITTERATION

#include "../Evenement.h"

template <size_t N>
class EvenementIteration : public Evenement<N>
{
	int k;
	double fx;
	double grad_norm;
	Vecteur<N> x;
public:
	EvenementDemarrage(const int& k, const double& fx, const double& grad_norm, const Vecteur<N>& x)
		: k(k), fx(fx), grad_norm(grad_norm), x(x) {}
};


#endif