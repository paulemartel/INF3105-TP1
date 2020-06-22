#ifndef LECTUREFICHIER_HPP_
#define LECTUREFICHIER_HPP_

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
