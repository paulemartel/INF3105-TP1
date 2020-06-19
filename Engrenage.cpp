#include "Engrenage.hpp"
#include "Constantes.hpp"

#include <iostream>

Engrenage::Engrenage (string nomPiece, int nombreDent) {
    
    if (nombreDent >= NOMBRE_DENT_MINIMUM) {
        nombreDentOuSillon = nombreDent;
    } else {
        cerr << "Erreur, nombre de dents invalide" << endl;
        exit(-1);
    }
    nom = nomPiece;
    typePiece = "composante";
}

