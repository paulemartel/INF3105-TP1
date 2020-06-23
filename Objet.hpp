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
    
    /**
     * (fonction surchargee dans Direct)
     * Etablit, selon le nombre de sillons de la vis qui
     * precede l'objet Direct, l'efficacite de ce dernier.
     * 
     * @param nombreSillon nombre de sillons de l'objet Vis 
     *     qui precede
    */  
    virtual void calculerEfficaciteDirectAvecVis(int const & nombreSillon);
};

#endif
