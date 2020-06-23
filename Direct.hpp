#ifndef DIRECT_HPP_
#define DIRECT_HPP_
/*
 * Classe fille de Lien, permet d'instancier des objets
 * representant des liens directs et de faire les calculs
 * connexes.
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

#include "Lien.hpp"

#include <string>
using namespace std;

class Direct : public Lien {
public:
/**
 * Construit un objet Direct.
*/
    Direct();

/**
 * Etablit, selon le nombre de sillons de la vis qui
 * precede l'objet Direct, l'efficacite de ce dernier.
 * 
 * @param nombreSillon nombre de sillons de l'objet Vis 
 *     qui precede
*/  
    void calculerEfficaciteDirectAvecVis(int nombreSillon);
};

#endif
