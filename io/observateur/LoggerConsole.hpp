#pragma once
#include <iostream>
#include <iomanip>
#include "../Observateur.hpp"
#include "../Evenement.hpp"

#include "../evenement/Demarrage.hpp"
#include "../evenement/EvenementIteration.h"
#include "../evenement/EvenementTerminaison.h"


template <size_t N>
class LoggerConsole : public Observateur<N> {
private:
int frequence_; // Ex: 1 (tout), 10 (tous les 10), 100 (tous les 100)

public:
	explicit LoggerConsole(int frequence = 1) : frequence_(frequence) {}
	// L'unique méthode qui reçoit les événements
	void onNotify(const Evenement<N>& event) override {

	// --- 1. GESTION ÉVÉNEMENT DÉMARRAGE ---
26 if (auto* e = dynamic_cast<const EvenementDemarrage<N>*>(&event)) {
27
28 std::cout << std::setw(3) << "" << "Point initial : "; e->x_initial.print();
std::cout << std::endl;,→
29 std::cout << std::setw(3) << "" << " Fonction : " << e->nom_fonction <<
std::endl;,→
30 std::cout << std::setw(3) << "" << " Méthode : " << e->nom_methode <<
std::endl;,→
31 std::cout << std::setw(3) << "" << " Max-iters : " << e->max_iter <<
std::endl << std::endl;,→
32
33 // En-tête
34 std::cout << std::setw(8) << "Iter." << std::setw(3) << " ";
35 std::cout << std::setw(15) << "Obj." << std::setw(3) << " ";
36 std::cout << std::setw(12) << "||Grad||" << std::setw(5) << " ";
37 std::cout << std::setw(10) << "Point" << std::endl << std::endl;
38 }
39
40 // --- 2. GESTION ÉVÉNEMENT ITÉRATION (AVEC FILTRE) ---
41 else if (auto* e = dynamic_cast<const EvenementIteration<N>*>(&event)) {
42
43 if (e->iter == 0 || e->iter % frequence_ == 0) {
44 std::cout << std::setw(8) << e->iter << std::setw(3) << " ";
45 std::cout << std::fixed << std::setprecision(5)
46 << std::setw(15) << e->f_val << std::setw(3) << " ";
47 std::cout << std::scientific << std::setprecision(2)
48 << std::setw(12) << e->grad_norm << std::setw(5) << " ";
49 std::cout << std::fixed;
50 e->x_actuel.print();
51 std::cout << "\n";
52 }
53 }
54
55 // --- 3. GESTION ÉVÉNEMENT TERMINAISON ---
56 else if (auto* e = dynamic_cast<const EvenementTerminaison<N>*>(&event)) 