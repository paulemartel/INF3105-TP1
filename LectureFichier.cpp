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

int main(int argc, char * argv []) {
    // fonction convertirFichierEnVecteur()
    string ligne;
    ifstream fichier ("test_3_lignes.txt");
    vector<Objet*> vecteur;
    
    if (fichier.is_open()) {
        while (getline (fichier, ligne)) {
            
            if (ligne.find("engrenage") != string::npos) {
                // ce qui suit pourrait etre une fonction dans Composante
                int position = ligne.find(" ");
                string nombre = ligne.substr(position + 1); 
                int nombreEnChiffres = stoi(nombre);
                Engrenage * piece = 
                    new Engrenage("engrenage", nombreEnChiffres, "composante");
                //cout << piece->typePiece << " avant" << endl;
                vecteur.push_back(piece);
                //cout << vecteur[0]->typePiece << " apres" << endl;            
            
            } else if (ligne.find("vis") != string::npos) {
                // idem
                int position = ligne.find(" ");
                string nombre = ligne.substr(position + 1);
                int nombreEnChiffres = stoi(nombre);
                Vis * piece = new Vis("vis", nombreEnChiffres, "composante");
                vecteur.push_back(piece);
            
            } else if (ligne.find("essieu") != string::npos) {
                // pas de nombreDentOuSillon, donc plus simple
                Essieu * piece = new Essieu("essieu", "lien");
                vecteur.push_back(piece);
            
            } else if (ligne.find("direct") != string::npos) {
                Direct * piece = new Direct("direct", "lien");
                vecteur.push_back(piece);
            
            } else if (ligne.find("chaine") != string::npos) {
                Chaine * piece = new Chaine("chaine", "lien");
                vecteur.push_back(piece);
            }
        }
        fichier.close();
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
   
    // fonction valider345()
    
    for (int i = 0; i < vecteur.size(); ++i) {
        // si message erreur identique dans constantes, regrouper le corps des fonctions
        // fonction valider 3
        if (vecteur[i]->nom == "vis" && vecteur[i + 1] != nullptr && vecteur[i + 1]->nom != "direct") {
            cerr << "le lien suivant une vis doit etre direct" << endl;
            exit(-1);
        }
        // fonction valider 4 et 5
        if ((vecteur[i]->nom == "direct" || vecteur[i]->nom == "chaine") && vecteur[i + 1]->nom != "engrenage") {
            cerr << "un lien direct peut seulement etre suivi d'un engrenage" << endl;
            exit(-1);
        }
        
        // on calcule l'efficacite des direct avec des vis
        if (vecteur[i]->nom == "direct" && vecteur[i - 1]->nom == "vis") {
            // fonction attribuerEfficaciteLien(), on passe le nombreDentOuSillon de la vis en param
            if (vecteur[i - 1]->nombreDentOuSillon == 1) {
                vecteur[i]->efficacite = 0.8;
            } else if (vecteur[i - 1]->nombreDentOuSillon == 2) {
                vecteur[i]->efficacite = 0.7;
            } else if (vecteur[i - 1]->nombreDentOuSillon == 3) {
                vecteur[i]->efficacite = 0.6;
            } else if (vecteur[i - 1]->nombreDentOuSillon == 4) {
                vecteur[i]->efficacite = 0.5;
            }
        }
    }
    
    // tests

    cout << vecteur[0]->nom << endl;
    cout << vecteur[0]->nombreDentOuSillon << endl;
    cout << vecteur[0]->typePiece << endl;

    cout << vecteur[1]->nom << endl;
    cout << vecteur[1]->efficacite << endl;
    cout << vecteur[1]->typePiece << endl;


    return 0;    
}
