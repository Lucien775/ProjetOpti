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



