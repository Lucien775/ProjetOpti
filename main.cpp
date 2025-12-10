#include "Optimiseur.hpp"

int main(){
    /*Paramètre généraux*/
    double alpha = 0.1;
    double epsilon = 10e-6;
    
    FonctionObjectif1 f1;
    DescenteGradient<2> dg(f1, alpha, epsilon, 100);
    Vecteur<2> x0 = {0.0, 0.0};
    dg.optimiser(x0);
    

    return 0;
}