#include <iostream>
#include "function.hpp"
template <size_t N>
class PasDeplacement {
public:
    virtual double calculerPas(const Vecteur<N>& xk, const Vecteur<N>& dk, const Vecteur<N>& gradxk, 
    const FonctionObjectif<N>& f) const = 0;

    virtual ~PasDeplacement() = default;

    virtual const double getPas() const = 0;
};


template <size_t N>
class PasFixe : public PasDeplacement<N> {
    public : 
    double alpha;
    PasFixe(double alpha){
        this->alpha = alpha;
    }
    double calculerPas(const Vecteur<N>& xk, const Vecteur<N>& dk, const Vecteur<N>& gradxk, const FonctionObjectif<N>& f) const override{
        return alpha;
    }
    //getter 

    const double getPas() const {

        return alpha;
    }
    ~PasFixe() = default;


};