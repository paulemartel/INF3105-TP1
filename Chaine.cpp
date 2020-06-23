#include "Chaine.hpp"


/**
 * Construit un objet Chaine.
 * 
 * @param nomPiece le nom de la piece ("chaine", ici)
*/
Chaine::Chaine(string nomPiece) {
    nom = nomPiece;
    typePiece = "lien";
    efficacite = 0.8;
}
