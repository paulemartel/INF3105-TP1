#include "Composante.hpp"

class Engrenage : public Composante {
    // attribut de classe
    int _nombreDent;

public:
    // constructeur
    Engrenage (int nombreDent);
    // getter
    int getNombreDent();
};
