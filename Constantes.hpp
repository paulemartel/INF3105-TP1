#ifndef CONSTANTES_HPP_
#define CONSTANTES_HPP_


#include <string>

using namespace std;



int const NOMBRE_DENT_MINIMUM = 6;
int const NOMBRE_SILLON_MINIMUM = 1;
int const NOMBRE_SILLON_MAXIMUM = 4;




/* Message */

string const MSSG_QUESTION_CONTINUER = 
"Voulez-vous lancer une autre analyse ? ('n' pour non, autre pour oui.)";
string const MSSG_REQUETE_VITESSE = 
"Quelle est la vitesse de rotation de la premiere composante ?";
string const MSSG_REQUETE_COUPLE = 
"Quel est le couple applique a la premiere composante ?";


/* Message d'erreur */

string const MSSG_ERR_REQUETE_PAS_DOUBLE = 
"Pas un double Veuillez entrer une nouvelle valeur.";

string const MSSG_ERR_COMPOSANTE_APRES_ESSIEU = 
"Il faut une composante apres un essieu.";
string const MSSG_ERR_COMPOSANTE_APRES_DIRECT = 
"Il faut une composante apres un lien direct.";
string const MSSG_ERR_COMPOSANTE_APRES_CHAINE = 
"Il faut une composante apres une chaine.";
string const MSSG_ERR_ALTERNANCE_COMPOSANTE_LIEN = 
"Il faut alterner composantes et liens.";
string const MSSG_ERR_COMPOSANTE_INVALIDE = 
"Composante invalide.";
string const MSSG_ERR_COUPLE_INVALIDE = "Ce n'est pas un couple valide.";
string const MSSG_ERR_DEVRAIT_NOMBRE_DENT = 
"Il devrait y avoir une valeur entiere pour le nombre de dents.";
string const MSSG_ERR_DEVRAIT_SILLON = 
"Il devrait y avoir une valeur entiere pour le nombre de sillons.";
string const MSSG_ERR_FICHIER_INEXISTANT = "Le fichier n'existe pas.";
string const MSSG_ERR_LIEN_INVALIDE = "Lien invalide.";
string const MSSG_ERR_MEME_SIGNE = 
"Les deux valeurs doivent avoir le meme signe.";
string const MSSG_ERR_NOMBRE_ARGUMENT = 
"Il devrait y avoir un et un seul argument.";
string const MSSG_ERR_NOMBRE_DENT_MINIMUM_P1 = "Il doit y avoir un minimum de ";
string const MSSG_ERR_NOMBRE_DENT_MINIMUM_P2 = " dents.";
string const MSSG_ERR_NOMBRE_DENT_MINIMUM = MSSG_ERR_NOMBRE_DENT_MINIMUM_P1 +
                                            to_string( NOMBRE_DENT_MINIMUM ) +
                                            MSSG_ERR_NOMBRE_DENT_MINIMUM_P2;
string const MSSG_ERR_NOMBRE_SILLON_P1 = "Le nombre de sillon doit etre entre ";
string const MSSG_ERR_NOMBRE_SILLON_P2 = " et ";
string const MSSG_ERR_NOMBRE_SILLON_P3 = ".";
string const MSSG_ERR_NOMBRE_SILLON = MSSG_ERR_NOMBRE_SILLON_P1 +
                                      to_string( NOMBRE_SILLON_MINIMUM ) +
                                      MSSG_ERR_NOMBRE_SILLON_P2 +
                                      to_string( NOMBRE_SILLON_MAXIMUM ) +
                                      MSSG_ERR_NOMBRE_SILLON_P3;
string const MSSG_ERR_SEULEMENT_DIRECT = 
"Seulement un lien direct peut apparaitre apres une vis.";
string const MSSG_ERR_SEULEMENT_ENGRENAGE_DIRECT = 
"Seulement un engrenage peut apparaitre apres un lien direct.";
string const MSSG_ERR_SEULEMENT_ENGRENAGE_CHAINE = 
"Seulement un engrenage peut apparaitre apres une chaine.";
string const MSSG_ERR_UNE_COMPOSANTE_MINIMUM = 
"Il doit y avoir au moins une composante.";
string const MSSG_ERR_VITESSE_INVALIDE = "Ce n'est pas une vitesse valide.";
string const MSSG_ERR_MANQUE_FICHIER_ARGUMENT = 
"Veuillez entrer un fichier en argument.";

#endif /* CONSTANTES_HPP_ */
