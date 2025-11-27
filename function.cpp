#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class IFonction{
public:
    virtual ~IFonction() = default;
    virtual double result(const vector<double>& x) const = 0;
    virtual vector<double> gradient(const vector<double>& x) const = 0;
    virtual size_t dimension() const = 0;
};

class Fonction1 : public IFonction{
public:
    //constructeur
    Fonction1() = default;

    size_t dimension() const override {return 2;}

    double result(const vector<double>& x) const override{
        double r = 0.0;
        if(x.size() != dimension()){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = x[0]*x[0] + 2*x[1]*x[1];
            return r;
        }
    }

    vector<double> gradient(const vector<double>& x) const override{
        vector<double> g;
        if(x.size() != dimension()){
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
public:
    //constructeur
    Fonction2() = default;

    size_t dimension() const override {return 3;}

    double result(const vector<double>& x) const override{
        double r = 0.0;
        if(x.size() != dimension()){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = x[0]*x[0] + 2*x[1]*x[1] + 3*x[2]*x[2];
            return r;
        }
    }

    vector<double> gradient(const vector<double>& x) const override{
        vector<double> g;
        if(x.size() != dimension()){
            cout<<"Erreur"<<endl;
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
public:
    //constructeur
    Fonction3() = default;

    size_t dimension() const override {return 2;}

    double result(const vector<double>& x) const override{
        double r = 0.0;
        if(x.size() != dimension()){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = (1-x[0])*(1-x[0]) + 100*(x[1] - x[0]*x[0])*(x[1] - x[0]*x[0]);
            return r;
        }
    }

    vector<double> gradient(const vector<double>& x) const override{
        vector<double> g;
        if(x.size() != dimension()){
            cout<<"Erreur"<<endl;
            return g;
        }
        else{
            g.push_back((-2)* (1 - x[0]) - 400 * x[0] * ( x[1] - x[0]*x[0] )   );
            g.push_back( 200 * ( x[1] - x[0]*x[0] ) );
            g.push_back(6*x[2]);
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