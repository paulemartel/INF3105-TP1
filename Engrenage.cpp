#include "Engrenage.hpp"
#include "Constantes.hpp"

#include <iostream>

Engrenage::Engrenage (int nombreDent) {
    
    if (nombreDent % 1 != 0) {
        cerr << MSSG_ERR_DEVRAIT_NOMBRE_DENT << endl;
        exit(-1);
    }
    if (nombreDent >= NOMBRE_DENT_MINIMUM) {
        nombreDentOuSillon = nombreDent;
    } else {
        cerr << MSSG_ERR_NOMBRE_DENT_MINIMUM << endl;
        exit(-1);
    }
    nom = "engrenage";
    typePiece = "composante";
}

