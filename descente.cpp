#include <iostream>
#include <vector>

#include "function.cpp"


using namespace std;

class DirDescenteRealisable{
public : 

    DirDescenteRealisable() = default;

    ~DirDescenteRealisable() = default ; 

    vector<double> Direction(vector<double> xk, IFonction& f){

        std::vector<double> g = f.gradient(xk);
        for(double v : g)
            v = -v;
        return g;
    }
};



