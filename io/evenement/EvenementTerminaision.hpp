#ifndef FIN
#define FIN

#include "../Evenement.h"

template <size_t N>
class EvenementTerminaison : public Evenement<N>
{
	Vecteur<N> x_final;
	double f_final;
	bool converged;
public:
	EvenementDemarrage(const Vecteur<N>& x_final, const double& f_final, const bool& converged)
		: x_final(x_final), f_final(f_final), converged(converged) {}
};


#endif