#include <iostream>

using namespace std;

class DirDescenteRealisable{

private : 
    std::vector<double> x_init;
    Fonction f;

public : 

    DirDescenteRealisable(){};

    DirDescenteRealisable(vector<double> pointInit, Fonction fObjective){
        this->x_init = pointInit;
        this->f = fObjective;
    };

    ~DirDescenteRealisable() = default ; 

    vector<double> Direction(vector<double> xk, Fonction f){

        return -f.gradient(xk);
    }



};



int main(){

    Fonction1 f1;
    Fonction2 f2;
    Fonction3 f3;

    double alpha = 0.1;
    double epsilon = 10e-6;
    vector<double> x_init(0.0,0.0);


    DirDescenteRealisable d1(x_init, f1);

    DirDescenteRealisable d2(x_init, f2);

    DirDescenteRealisable d3(x_init, f3);

    Algorithme algo(f1, d1, alpha, epsilon);

    vector<double> res = algo.minimize(x_init);

    cout << "Résultat de la minimisation de la fonction 1 : " << res << endl;



    return 0;
}