#include "Engrenage.hpp"

#include <iostream>

Engrenage::Engrenage (int nombreDent) {
    
    if (nombreDent >= 6) {
        nombreDentOuSillon = nombreDent;
    } else {
        cerr << "Erreur (mettre constante ici)" << endl;
        exit(-1);
    }
}

int Engrenage::getNombreDent() {
    return nombreDentOuSillon;
}

