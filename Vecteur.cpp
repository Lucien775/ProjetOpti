#include <iostream>



using namespace std;

template <size_t N>

class Vecteur : public std::array<double, N>{

private : 
    array<double,N> point;
    size_t dimension = N;
    
public : 

//Constructeur Destructeur 

    Vecteur() = default;

    ~Vecteur() = default ;


//opérateurs

    Vecteur addition_Vecteur(Vecteur v1, Vecteur v2){

        Vecteur new_vec;
        for(int i = 0, i<N, i++){
            new_vec->point[i] = v1->point[i] + v2->point[i];
        }
        return new_vec;
    }

    Vecteur soustraction_Vecteur(Vecteur v1, Vecteur v2){
        Vecteur new_vec;
        for(int i = 0, i<N, i++){
            new_vec->point[i] = v1->point[i] - v2->point[i];
        }
        return new_vec;
    }

    Vecteur multiplicateur_Vecteur(Vecteur v1, Vecteur v2){
        Vecteur new_vec;
        for(int i = 0, i<N, i++){
            new_vec->point[i] = v1->point[i] * v2->point[i];
        }
        return new_vec;
    }

    Vecteur multiplicateur_Scalaire(Vecteur v1, double k){
        Vecteur new_vec;
        for(int i = 0, i<N, i++){
            new_vec->point[i] = v1->point[i] * k;
        }
        return new_vec;
    }

    double calculNorm(Vecteur v1){
        double norm = 0.0;

        for(double i : v1){
            norm += i*i;
        }
        
        return sqrt(norm);
    }





// getters
    const size_t getDim() const {
        return dimension;
    }
// setters 
    void setValue(array<double,N> new_point){

        this->point = new_point;
    }


};