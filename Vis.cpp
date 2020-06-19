#include "Vis.hpp"
#include "Constantes.hpp"

#include <iostream>

Vis::Vis (string nomPiece, int nombreSillon) {
    
    if (nombreSillon >= NOMBRE_SILLON_MINIMUM 
            && nombreSillon <= NOMBRE_SILLON_MAXIMUM) {
        nombreDentOuSillon = nombreSillon;
    } else {
        cerr << "erreur, nombre de sillons invalide" << endl;
        exit(-1);
    }
    nom = nomPiece;
    typePiece = "composante";
}

