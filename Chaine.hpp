#ifndef CHAINE_HPP_
#define CHAINE_HPP_

/*
 * Classe fille de Lien, permet d'instancier des objets
 * representant des chaines.
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

class Chaine : public Lien {
public:
/**
 * Construit un objet Chaine.
*/
    Chaine();
};

#endif
