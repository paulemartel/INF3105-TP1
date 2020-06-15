#ifndef _COMPOSANTE_HPP
#define _COMPOSANTE_HPP

#include "Objet.hpp"

#include <string>
using namespace std;

class Composante : public Objet {
    // attribut de classe
public:
    string type = "composante";
// va probablement contenir des fonctions de calcul pour Engrenage et Vis
};

#endif
