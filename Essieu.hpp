#ifndef ESSIEU_HPP_
#define ESSIEU_HPP_

/*
 * Classe fille de Composante, permet d'instancier des objets
 * representant des essieux.
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

class Essieu : public Lien {
public:
    Essieu(string nomPiece);

};
#endif