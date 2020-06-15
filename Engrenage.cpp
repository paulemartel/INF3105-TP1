#include "Engrenage.hpp"

#include <iostream>

Engrenage::Engrenage (string nomPiece, int nombreDent, string typeObjet) {
    
    if (nombreDent >= 6) {
        nombreDentOuSillon = nombreDent;
    } else {
        cerr << "Erreur (mettre constante ici)" << endl;
        exit(-1);
    }
    nom = nomPiece;
    typePiece = typeObjet;
}

int Engrenage::getNombreDent() {
    return nombreDentOuSillon;
}

