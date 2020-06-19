#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Engrenage.hpp"
#include "Vis.hpp" 
#include "Essieu.hpp"
#include "Direct.hpp"
#include "Chaine.hpp"

using namespace std;

class LectureFichier {

    void validerComposanteFin(vector<Objet*> vecteur);
    void validerReglesFormationMecanisme(vector<Objet*> vecteur);

public:
    vector<Objet*> convertirFichierEnVecteur();
    void validerDonnees(vector<Objet*> vecteur);
    double calculerEfficaciteTotale(vector<Objet*> vecteur);     
};
// ----- APPELS DANS LA MAIN --------
//
// vector<Objet*> vecteur = convertirFichierEnVecteur();
// validerDonnees(vecteur);
// double efficaciteTotale = calculerEfficacite(vecteur);
//
