#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Descente_gradient {
public:

};

class IFonction{

    public:
    size_t dimension;
    virtual double result(  vector<double> x) = 0;
    virtual vector<double> gradient( vector<double> x) = 0;
};

class Fonction1 : public IFonction{
    //constructeur
    Fonction1(){}
    ~Fonction1(){}
    size_t dimension = 2;

    double result(  vector<double> x) override{
        double r = 0.0;
        if(x.size() != dimension){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = x[0]*x[0] + 2*x[1]*x[1];
            return r;
        }
    }

    vector<double> gradient( vector<double> x){
        vector<double> g;
        if(x.size() != dimension){
            cout<<"Erreur"<<endl;
            return g;
        }
        else{
            g.push_back(2*x[0]);
            g.push_back(4*x[1]);
            return g;
        }
    }
};

class Fonction2 : public IFonction{
    //constructeur
    Fonction2(){}
    ~Fonction2(){}
    size_t dimension = 3;

    double result(  vector<double> x) override{
        double r = 0.0;
        if(x.size() != dimension){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = x[0]*x[0] + 2*x[1]*x[1] + 3*x[2]*x[2];
            return r;
        }
    }

    vector<double> gradient( vector<double> x){
        vector<double> g;
        if(x.size() != dimension){
            cout<<"Erreur de dimension"<<endl;
            return g;
        }
        else{
            g.push_back(2*x[0]);
            g.push_back(4*x[1]);
            g.push_back(6*x[2]);
            return g;
        }
    }
};

class Fonction3 : public IFonction{
    //constructeur
    Fonction3(){}
    ~Fonction3(){}
    size_t dimension = 2;

    double result(  vector<double> x) override{
        double r = 0.0;
        if(x.size() != dimension){
            cout<<"Erreur de dimension"<<endl;
            return 0.0;
        }
        else{
            r = (1-x[0])*(1-x[0]) + 100*(x[1] - x[0]*x[0])*(x[1] - x[0]*x[0]);
            return r;
        }
    }

    vector<double> gradient( vector<double> x){
        vector<double> g;
        if(x.size() != dimension){
            cout<<"Erreur de dimension"<<endl;
            return g;
        }
        else{
            g.push_back((-2)* (1 - x[0]) - 400 * x[0] * ( x[1] - x[0]*x[0] )   );
            g.push_back( 200 * ( x[1] - x[0]*x[0] ) );

            return g;
        }
    }
};

/*
class IndexOutOfBoundsException : public exception{
    private:
    string message;

    public:
    explicit IndexOutOfBoundsException(const string& msg) : message(msg)
};

*/