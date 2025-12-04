#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <size_t N>
class FonctionObjectif{
public:
    virtual ~IFonction() = default;
    virtual double result(const vector<double>& x) const = 0;
    virtual vector<double> gradient(const vector<double>& x) const = 0;
    virtual size_t dimension() const = 0;

    virtual Vecteur<N> calculerGradient (const Vecteur& x) = 0;
    virtual double evaluer( const Vecteur<N>& x) = 0;
    virtual void afficher_f() = 0;
};

//template <size_t N>
class FonctionObjectif1 : public FonctionObjectif{
public:
    //constructeur
    FonctionObjectif1() = default;

    size_t dimension() const override {return 2;}

    double evaluer(const Vecteur<2>& x) const override{
        double r = 0.0;
        if(x.getDim() != dimension()){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = x[0]*x[0] + 2*x[1]*x[1];
            return r;
        }
    }

    Vecteur<2> calculerGradient(const Vecteur<2>& x) const override{
        vector<double> g;
        if(x.getDim() != dimension()){
            cout<<"Erreur"<<endl;
            return g;
        }
        else{

            double v1 = 2*x[0] ;
            double v2 = 4*x[1] ;
            //array<double, dimension()> v = {v1, v2};

            g[0] = v1;
            g[1] = v2;

            /*g.push_back(2*x[0]);
            g.push_back(4*x[1]); */
            return g;
        }
    }

    void afficher_f(){
        cout<< "Fonction q1"<<endl;
        cout<< " x[0]*x[0] + 2*x[1]*x[1] "<<endl;
    }
};

//template <size_t N>

class FonctionObjectif2 : public FonctionObjectif{
public:
    //constructeur
    FonctionObjectif2() = default;

    size_t dimension() const override {return 3;}

    double evaluer(const Vecteur<3>& x) const override{
        double r = 0.0;
        if(x.getDim() != dimension()){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = x[0]*x[0] + 2*x[1]*x[1] + 3*x[2]*x[2];
            return r;
        }
    }

    Vecteur<3> calculerGradient(const Vecteur<3>& x) const override{
        Vecteur<3> g;
        if(x.getDim() != dimension()){
            cout<<"Erreur"<<endl;
            return g;
        }
        else{

            double v1 = 2*x[0] ;
            double v2 = 4*x[1] ;
            double v3 = 6*x[2] ;
            //array<double, dimension()> v = {v1, v2, v3};

            g[0] = v1;
            g[1] = v2;
            g[2] = v3;
            /*g.push_back(2*x[0]);
            g.push_back(4*x[1]);
            g.push_back(6*x[2]); */
            return g;
        }
    }

        void afficher_f(){
        cout<< "======Fonction q2======"<<endl;
        cout<< " x[0]*x[0] + 2*x[1]*x[1] + 3*x[2]*x[2] "<<endl;
    }
};

//template <size_t N>

class FonctionObjectif3 : public FonctionObjectif{
public:
    //constructeur
    FonctionObjectif3() = default;

    size_t dimension() const override {return 2;}

    double evaluer(const Vecteur<2>& x) const override{
        double r = 0.0;
        if(x.getDim() != dimension()){
            cout<<"Erreur"<<endl;
            return 0.0;
        }
        else{
            r = (1-x[0])(1-x[0]) + 100(x[1] - x[0]x[0])(x[1] - x[0]*x[0]);
            return r;
        }
    }

    Vecteur<2> calculerGradient(const Vecteur<2>& x) const override{
        Vecteur<2> g;
        if(x.getDim() != dimension()){
            cout<<"Erreur"<<endl;
            return g;
        }
        else{
            double v1 = (-2)* (1 - x[0]) - 400 * x[0] * ( x[1] - x[0]*x[0] ) ;
            double v2 = 200 * ( x[1] - x[0]*x[0] );
            //array<double, dimension()> v = {v1, v2};

            g[0] = v1;
            g[1] = v2 ;

            /*g.push_back((-2) (1 - x[0]) - 400 * x[0] * ( x[1] - x[0]*x[0] )   );
            g.push_back( 200 * ( x[1] - x[0]*x[0] ) ); */

            return g;
        }
    }

    void afficher_f(){
        cout<< "=====Fonction r1====="<<endl;
        cout<< " (1-x[0])(1-x[0]) + 100(x[1] - x[0]x[0])(x[1] - x[0]*x[0]) "<<endl;
    }
    
};





/*
class IndexOutOfBoundsException : public exception{
    private:
    string message;

    public:
    explicit IndexOutOfBoundsException(const string& msg) : message(msg)
};