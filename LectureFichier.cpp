#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Engrenage.hpp"

using namespace std;
// creer fonction convertirFichierEnVecteur()
int main(int argc, char * argv []) {
    string ligne;
    ifstream fichier ("test_3_lignes.txt");
    vector<Engrenage*> tableau;
    
    if (fichier.is_open()) {
        while (getline (fichier, ligne)) {
            
            if (ligne.find("engrenage") != string::npos) {
                // ce qui suit pourrait etre une fonction pour les Vis et les Engrenage
                // on trouve la  position de l'espace
                int position = ligne.find(" ");
                // on isole le nombre
                string nombre = ligne.substr(position + 1); 
                // on le convertit en int
                int nombreEnChiffres = stoi(nombre);
                //tableau.push_back(new Engrenage(nombreEnChiffres));
                Engrenage * piece = new Engrenage(nombreEnChiffres);
                tableau.push_back(piece);            
            }
        }
        fichier.close();
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
    
    cout << tableau[0]->getNombreDent() << endl;
    //for (int i = 0; i < tableau.size(); ++i) {
    //    cout << tableau[i] << endl;
    //}

    return 0;
    
}
