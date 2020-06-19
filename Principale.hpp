#ifndef _PRINCIPALE_HPP
#define _PRINCIPALE_HPP

#include <iostream>
#include <string>
#include "Constantes.hpp"
#include <vector>
#include "LectureFichier.hpp"

using namespace std;

class Principale {

    //attributs
    double demandeDouble();
    bool memeSigne(double num1,double num2);
    void analyseMouvement(double vitesseComposante, double couple, vector<Objet*> vecteur);
    double calculR(Objet* composante1, Objet* lien, Objet* composante2);
};

#endif
