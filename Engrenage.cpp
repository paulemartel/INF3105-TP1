#include "Engrenage.hpp"

#include <iostream>

Engrenage::Engrenage (string nomPiece, int nombreDent) {
    
    if (nombreDent >= 6) {
        nombreDentOuSillon = nombreDent;
    } else {
        cerr << "Erreur, nombre de dents invalide" << endl;
        exit(-1);
    }
    nom = nomPiece;
    typePiece = "composante";
}

