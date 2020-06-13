#include "Engrenage.hpp"

Engrenage::Engrenage (int nombreDent) {
    nombreDentOuSillon = nombreDent;
}

int Engrenage::getNombreDent() {
    return nombreDentOuSillon;
}

