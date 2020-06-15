#include "Lien.hpp"

#include <string>
using namespace std;

class Essieu : public Lien {
public:
    double efficacite = 1.0;
    Essieu(string nomPiece, string typeObjet); // on veut tu construire un essieu avec les deux pieces qui l'entourent?

};
