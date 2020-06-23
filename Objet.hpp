#ifndef OBJET_HPP_
#define OBJET_HPP_

/*
 * Classe mere de Composante et Lien, elle permet de 
 * regrouper tous les elements du mecanisme dans un
 * meme vector et donc facilite leur traitement.
 *   
 * Auteures : Paule Martel et Gabrielle Poitras
 * Code permanent : 
 *     MARP16569700
 *     POIG16519008
 * Courriel : 
 *     martel.paule@courrier.uqam.ca
 *     poitras.gabrielle.2@courrier.uqam.ca
 * Cours : INF3105-30
 * Date : 2020-06-22
 */

#include <string>
using namespace std;

class Objet {

public:
    string nom;
    int nombreDentOuSillon;
    double efficacite;
    string typePiece;
    
    virtual void calculerEfficaciteDirectAvecVis(int nombreSillon);
};

#endif
