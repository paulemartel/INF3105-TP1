#include "Vis.hpp"

#include <iostream>

Vis::Vis (string nomPiece, int nombreSillon) {
    
    if (nombreSillon > 0 && nombreSillon < 5) {
        nombreDentOuSillon = nombreSillon;
    } else {
        cerr << "erreur, nombre de sillons invalide" << endl;
        exit(-1);
    }
    nom = nomPiece;
    typePiece = "composante";
}

