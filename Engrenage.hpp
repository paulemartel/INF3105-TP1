#include "Composante.hpp"

#include <string>
using namespace std;

class Engrenage : public Composante {
    // attribut de classe
    //int _nombreDent;

public:
    // constructeur
    Engrenage (int nombreDent);
    // getter
    int getNombreDent();
};
