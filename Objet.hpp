#ifndef _OBJET_HPP
#define _OBJET_HPP

#include <string>
using namespace std;

class Objet {

    //attributs
public:
    string nom;
    int nombreDentOuSillon;
    double efficacite;
    string typePiece;
    void calculerEfficaciteDirectAvecVis(int nombreSillon);
};

#endif
