#ifndef LECTUREFICHIER_HPP_
#define LECTUREFICHIER_HPP_

/*
 * Lit le fichier entre en argument a la ligne de commande, puis
 * en extrait le mecanisme (composantes et liens) et les place
 * dans un vector.
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


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Engrenage.hpp"
#include "Vis.hpp" 
#include "Essieu.hpp"
#include "Direct.hpp"
#include "Chaine.hpp"
#include "Constantes.hpp"

using namespace std;

class LectureFichier {
    
    Objet* creationComposante(ifstream& fichier, string nom);
    void validerComposanteFin(vector<Objet*> vecteur);
    void validerReglesFormationMecanisme(vector<Objet*> vecteur);
    void estVide(ifstream& fichier);
    void indiquerComposanteOuLienInvalide(vector<Objet*> vecteur);
public:
    string nomFichier; // rendre private a la fin

    LectureFichier(string fichierEntre);
    vector<Objet*> convertirFichierEnVecteur();
    void validerDonnees(vector<Objet*> const& vecteur);
};

#endif
