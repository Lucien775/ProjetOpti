#include <iostream>
#include <vector>

#include "function.cpp"


using namespace std;

class DirDescenteRealisable{
public : 

    DirDescenteRealisable() = default;
    ~DirDescenteRealisable() = default ; 

    vector<double> Direction(const vector<double>& xk, IFonction& f){
        vector<double> g = f.gradient(xk);
        for(double &v : g)
            v = -v;
        return g;
    }
};



