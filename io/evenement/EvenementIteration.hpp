#ifndef ITTERATION
#define ITTERATION

#include "../Evenement.hpp"

template <size_t N>
class EvenementIteration : public Evenement<N> {
public:
    EvenementIteration(const int& k, const double& grad_norm, const double& fx, const Vecteur<N>& x) 
    {
        this->iteration = k;
        this->valeur_f = fx;
        this->grad_norm = grad_norm;
        this->point = x;
    }

    int iteration;
    double valeur_f;
    double grad_norm;
    Vecteur<N> point;
};



#endif