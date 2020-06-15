#include "Lien.hpp"

#include <string>
using namespace std;

class Chaine : public Lien {
public:
    double efficacite = 0.8;
    Chaine(string nomPiece, string typeObjet); // on veut tu construire un essieu avec les deux pieces qui l'entourent?

};
