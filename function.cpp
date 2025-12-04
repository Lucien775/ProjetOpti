#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.cpp"

using namespace std;

template <size_t N>
class FonctionObjectif {
public:
    virtual ~FonctionObjectif() = default;

    virtual double evaluer(const Vecteur<N>& x) const = 0;
    virtual Vecteur<N> calculerGradient(const Vecteur<N>& x) const = 0;
    virtual void afficher_f() const = 0;
};

class FonctionObjectif1 : public FonctionObjectif<2> {
public:
    double evaluer(const Vecteur<2>& x) const override {
        return x[0]*x[0] + 2*x[1]*x[1];
    }

    Vecteur<2> calculerGradient(const Vecteur<2>& x) const override {
        Vecteur<2> g;
        g[0] = 2 * x[0];
        g[1] = 4 * x[1];
        return g;
    }

    void afficher_f() const override {
        std::cout << "q1(x) = x1^2 + 2*x2^2\n";
    }
};

class FonctionObjectif2 : public FonctionObjectif<3> {
public:
    double evaluer(const Vecteur<3>& x) const override {
        return x[0]*x[0] + 2*x[1]*x[1] + 3*x[2]*x[2];
    }

    Vecteur<3> calculerGradient(const Vecteur<3>& x) const override {
        Vecteur<3> g;
        g[0] = 2 * x[0];
        g[1] = 4 * x[1];
        g[2] = 6 * x[2];
        return g;
    }

    void afficher_f() const override {
        std::cout << "q2(x) = x1^2 + 2*x2^2 + 3*x3^2\n";
    }
};
class FonctionObjectif3 : public FonctionObjectif<2> {
public:
    double evaluer(const Vecteur<2>& x) const override {
        return (1 - x[0])*(1 - x[0]) + 100*(x[1] - x[0]*x[0])*(x[1] - x[0]*x[0]);
    }

    Vecteur<2> calculerGradient(const Vecteur<2>& x) const override {
        Vecteur<2> g;

        g[0] = -2*(1 - x[0]) - 400*x[0]*(x[1] - x[0]*x[0]);
        g[1] =  200*(x[1] - x[0]*x[0]);

        return g;
    }

    void afficher_f() const override {
        std::cout << "r(x) = (1-x)^2 + 100(y-x^2)^2\n";
    }
};
