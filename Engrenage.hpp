#include "Composante.hpp"

#include <string>
using namespace std;

class Engrenage : public Composante {

public:
    // constructeur
    Engrenage (string nomPiece, int nombreDent);
    // getter
    int getNombreDent();
};
