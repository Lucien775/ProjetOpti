#include "Optimiseur.hpp"

int main(){
    /*Paramètre généraux*/
    double alpha = 0.1;
    double epsilon = 10e-6;
    
    //test f1
    FonctionObjectif1 f1;
    DescenteGradient<2> dg(f1, alpha, epsilon, 100);
    Vecteur<2> x0;
    x0[0] = 3.0;
    x0[1] = 5.0;
    dg.optimiser(x0);
    
    //test f2
    FonctionObjectif2 f2;
    DescenteGradient<3> dg2(f2, alpha, epsilon, 100);
    Vecteur<3> x2;
    x2[0] = 3.0;
    x2[1] = 5.0;
    x2[2] = 2.0;
    dg2.optimiser(x2);

    //test f3
    FonctionObjectif3 f3;
    DescenteGradient<2> dg3(f3, alpha, epsilon, 100);
    Vecteur<2> x3;
    x3[0] = 0.0;
    x3[1] = 0.0;
    dg3.optimiser(x3);

    return 0;
}