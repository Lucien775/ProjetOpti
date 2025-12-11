#ifndef FIN
#define FIN

#include "../Evenement.hpp"

template <size_t N>
class EvenementTerminaison : public Evenement<N> {
public:
    EvenementTerminaison(const Vecteur<N>& x_final, const double& f_final, const bool& converged) 
    {
        this->x_final = x_final;
        this->f_final = f_final;
        this->converged = converged;
    }
	Vecteur<N> x_final;
	double f_final;
	bool converged;
};


#endif