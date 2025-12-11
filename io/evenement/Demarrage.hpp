#ifndef DEMARRAGE
#define DEMARRAGE 

#include "../Evenement.hpp"

template <size_t N>
class EvenementDemarrage<N> : public Evenement<N>
{
	std::string nomAlgo;
	Vecteur<N> x0;
	FonctionObjectif<N> f;
	int max_iter;
public:
	EvenementDemarrage(const std::string& nomAlgo, const Vecteur<N> x0, const FonctionObjectif<N>& f, int max_iter)
		: nomAlgo(nomAlgo), x0(x0), f(f), max_iter(max_iter) {}
};

class EvenementDemarrage : public Evenement<N> {
public:
    EvenementDemarrage(const std::string& nomAlgo, const Vecteur<N> x0, const FonctionObjectif<N>& f, int max_iter) 
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