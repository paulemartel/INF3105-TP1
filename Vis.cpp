#include "Vis.hpp"

#include <iostream>

Vis::Vis (string nomPiece, int nombreSillon, string typeObjet) {
    
    if (nombreSillon > 0 && nombreSillon < 5) {
        nombreDentOuSillon = nombreSillon;
    } else {
        cerr << "erreur (mettre constante ici)" << endl;
        exit(-1);
    }
    nom = nomPiece;
    typePiece = typeObjet;
}

int Vis::getNombreSillon() {
    return nombreDentOuSillon;
}

