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
    ifstream fichier ("tests/testi6.txt");
    vector<Objet*> vecteur;
    
    if (fichier.is_open()) {
        // le fichier est-il vide?
        if (fichier.peek() == EOF) {
            cerr << "Fichier vide" << endl;
            exit(-1);
        }

        while (getline (fichier, ligne)) {
            
            if (ligne.find("engrenage") != string::npos) {
                int position = ligne.find(" ");
                string nombre = ligne.substr(position + 1); 
                for (char c : nombre) {
                    if (!isdigit(c) && c != '-') {
                        cerr << "Fichier invalide, caracteres invalides" << endl;
                        exit(-1);
                    }
                }
                int nombreEnChiffres = stoi(nombre);
                Engrenage * piece = 
                    new Engrenage("engrenage", nombreEnChiffres);
                vecteur.push_back(piece);         
            
            } else if (ligne.find("vis") != string::npos) {
                int position = ligne.find(" ");
                string nombre = ligne.substr(position + 1);
                for (char c : nombre) {
                    if (!isdigit(c) && c != '-') {
                        cerr << "Fichier invalide, caracteres invalides" << endl;
                        exit(-1);
                    }
                }
                int nombreEnChiffres = stoi(nombre);
                Vis * piece = new Vis("vis", nombreEnChiffres);
                vecteur.push_back(piece);
            
            } else if (ligne.find("essieu") != string::npos) {
                Essieu * piece = new Essieu("essieu");
                vecteur.push_back(piece);
            
            } else if (ligne.find("direct") != string::npos) {
                Direct * piece = new Direct("direct");
                vecteur.push_back(piece);
            
            } else if (ligne.find("chaine") != string::npos) {
                Chaine * piece = new Chaine("chaine");
                vecteur.push_back(piece);
            } else {
                cerr << "Fichier invalide" << endl;
                exit(-1); 
            }
        }
        fichier.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier" << endl;
        exit(-1);
    }
     
        
    int dernierePosition = vecteur.size() - 1;
    if (vecteur[dernierePosition]->typePiece != "composante") {
        cerr << "Fichier invalide, fini pas par une composante" << endl;
        exit(-1);
    }

    // fonction valider345()
    for (int i = 0; i < vecteur.size(); ++i) {
        //est-ce qu'on alterne composante et lien?
        //les composantes seront toujours placees a des indices pairs
        if (i % 2 == 1 && vecteur[i]->typePiece == "composante") {
            cerr << "Fichier invalide, on alterne pas lien et composante" << endl;
            exit(-1);
        }
                
        // TODO si meme msg erreur identique dans constantes, regrouper le corps des fonctions
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
            // Direct::calculerEfficaciteDirect(int dentsOuSillons)
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
    
    // calculerEfficacite()

    double efficaciteTotale = 0.0;
     
    for (int i = 0; i < vecteur.size(); ++i) {
        if (vecteur[i]->typePiece == "lien") {
            efficaciteTotale = 
                efficaciteTotale == 0 ? 
                vecteur[i]->efficacite : 
                efficaciteTotale * vecteur[i]->efficacite;  
        }    
    }

    // tests

    for (int i = 0; i < vecteur.size(); ++i) {
        Objet* element = vecteur[i];
        cout << "nom : " << element->nom << endl;
        if (element->typePiece == "composante") {
            cout << "nombreDentOuSillon : " << element->nombreDentOuSillon << endl; 
        } else {
            cout << "efficacite : " << element->efficacite << endl;
        }
        cout << "\n" << endl;
    }


    return 0;    
}
