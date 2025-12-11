#ifndef DEMARRAGE
#define DEMARRAGE 

#include "../Evenement.hpp"

template <size_t N>
class EvenementDemarrage : public Evenement<N> {
public:
    EvenementDemarrage(const std::string& nomAlgo, const Vecteur<N> x0, const FonctionObjectif<N>& f, int max_iter) 
    {
        this->nomAlgo = nomAlgo;
        this->x0 = x0;
        this->f = f;
        this->max_iter = max_iter;
    }
	std::string nomAlgo;
	Vecteur<N> x0;
	FonctionObjectif<N>& f;
	int max_iter;
};


#endif