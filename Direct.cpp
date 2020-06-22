#include "Direct.hpp"
#include <iostream> // FLUSHER
Direct::Direct(string nomPiece) {
    nom = nomPiece;
    typePiece = "lien";
    efficacite = 0.9; 
}

void Direct::calculerEfficaciteDirectAvecVis(int nombreSillon) {
    
    if (nombreSillon == 1) {
        this->efficacite = 0.8;
    } else if (nombreSillon == 2) {
        this->efficacite = 0.7;
    } else if (nombreSillon == 3) {
        this->efficacite = 0.6;
    } else if (nombreSillon == 4) {
        this->efficacite = 0.5;
    }
}


