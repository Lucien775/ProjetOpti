#include <iostream>
#include "function.hpp"
template <size_t N>
class PasDeplacement {
public:
    virtual double calculerPas(const Vecteur<N>& xk, const Vecteur<N>& dk, const Vecteur<N>& gradxk, 
    const FonctionObjective<N>& f) const = 0;

    virtual ~PasDeplacement() = default;
};