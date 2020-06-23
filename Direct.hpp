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
    Direct(string nomPiece);
    void calculerEfficaciteDirectAvecVis(int nombreSillon);
};

#endif