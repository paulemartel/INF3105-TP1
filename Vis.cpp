#include "Vis.hpp"

#include <iostream>

Vis::Vis (int nombreSillon) {
    
    if (nombreSillon > 0 && nombreSillon < 5) {
        nombreDentOuSillon = nombreSillon;
    } else {
        cerr << "erreur (mettre constante ici)" << endl;
        exit(-1);
    }
}

int Vis::getNombreSillon() {
    return nombreDentOuSillon;
}

