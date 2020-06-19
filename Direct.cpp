#include "Direct.hpp"

Direct::Direct(string nomPiece) {
    nom = nomPiece;
    typePiece = "lien";
    efficacite = 0.9; 
}


void Direct::calculerEfficaciteDirectAvecVis(int nombreSillon) {
    if (nombreSillon == 1) {
        efficacite = 0.8;
    } else if (nombreSillon == 2) {
        efficacite = 0.7;
    } else if (nombreSillon == 3) {
        efficacite = 0.6;
    } else if (nombreSillon == 4) {
        efficacite = 0.5;
    }
}


