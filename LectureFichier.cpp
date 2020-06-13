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

// creer fonction convertirFichierEnVecteur()
int main(int argc, char * argv []) {
    string ligne;
    ifstream fichier ("test_3_lignes.txt");
    vector<Objet*> tableau;
    
    if (fichier.is_open()) {
        while (getline (fichier, ligne)) {
            
            if (ligne.find("engrenage") != string::npos) {
                // ce qui suit pourrait etre une fonction dans Composante
                int position = ligne.find(" ");
                string nombre = ligne.substr(position + 1); 
                int nombreEnChiffres = stoi(nombre);
                Engrenage * piece = new Engrenage(nombreEnChiffres);
                tableau.push_back(piece);            
            } else if (ligne.find("vis") != string::npos) {
                // idem
                int position = ligne.find(" ");
                string nombre = ligne.substr(position + 1);
                int nombreEnChiffres = stoi(nombre);
                Vis * piece = new Vis(nombreEnChiffres);
                tableau.push_back(piece);
            } else if (ligne.find("essieu") != string::npos) {
                // les liens n'ont pas de nombre de dents ou de sillons, alors c'est plus simple
                Essieu * piece = new Essieu();
                tableau.push_back(piece);
            } else if (ligne.find("direct") != string::npos) {
                Direct * piece = new Direct();
                tableau.push_back(piece);
            } else if (ligne.find("chaine") != string::npos) {
                Chaine * piece = new Chaine();
                tableau.push_back(piece);
            }
        }
        fichier.close();
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
   
    // tests d'acces
    int testVis = tableau.at(0)->nombreDentOuSillon;
    cout << testVis << endl;
    int testEngrenage = tableau.at(2)->nombreDentOuSillon;
    cout << testEngrenage << endl;
    // VALIDATIONS

     



    return 0;    
}
