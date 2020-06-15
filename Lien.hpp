#ifndef _LIEN_HPP
#define _LIEN_HPP

#include "Objet.hpp"

#include <string>
using namespace std;

class Lien : public Objet {

    //attribut de classe
public:    
    string type = "lien";
    // vide pour le moment, va contenir des calculs, on assume
};

#endif
