#ifndef VIS_HPP_
#define VIS_HPP_

/*
 * Classe fille de Composante, permet d'instancier des objets
 * representant des vis.
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

#include "Composante.hpp"
#include <string>

using namespace std;

class Vis : public Composante {
      
public:
    /**
     * Construit un objet Vis.
     * 
     * @param nombreSillon nombre de sillons associe
     *     a la vis dans le fichier d'entree
    */ 
    Vis (int const & nombreSillon);
};

#endif
