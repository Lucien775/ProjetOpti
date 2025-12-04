#include <iostream>
#include <array>
#include <math.h>



using namespace std;

template <size_t N>
class Vecteur : public std::array<double, N>{
public : 

//Constructeur Destructeur 

    Vecteur() = default;

    ~Vecteur() = default ;


//opérateurs

    Vecteur<N> operator+(const Vecteur& v2){

        Vecteur new_vec;
        for(int i = 0; i<N; i++){
            new_vec[i] = (*this)[i] + v2[i];
        }
        return new_vec;
    }

    Vecteur<N> operator-(const Vecteur& v2){
        Vecteur new_vec;
        for(int i = 0; i<N; i++){
            new_vec[i] = (*this)[i] - v2[i];
        }
        return new_vec;
    }

    Vecteur<N> operator*(const double& k){
        Vecteur new_vec;
        for(int i = 0; i<N; i++){
            new_vec[i] = (*this)[i] * k;
        }
        return new_vec;
    }



    double calculNorm(){
        double norm = 0.0;

        for(double i : (*this)){
            norm += i*i;
        }

        return sqrt(norm);
    }

};