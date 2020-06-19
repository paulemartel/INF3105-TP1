#include "LectureFichier.hpp"

vector<Objet*> LectureFichier::convertirFichierEnVecteur() {
    ifstream fichier ("tests/testv12.txt");
    vector<Objet*> vecteur;
    
    if (fichier.is_open()) {
        
        // le fichier est-il vide?
        if (fichier.peek() == EOF) {
            cerr << "Fichier vide" << endl;
            exit(-1);
        }

        // on part la lecture en continue
        char c;
        bool debutMot;
        bool debutNbr;
        bool finMot;
        bool finNbr;
        string motComplet = "";
        string nbrComplet = "";

        while (fichier.get(c)) {
            
            // on trouve un mot            
            if (c != ' ' && c != '\n') {
                debutMot = true; // on indique le debut d'un mot
                motComplet += c; // on construit le mot
            } else if (debutMot == true && (c == ' ' || c == '\n')) {
                finMot = true;
                debutMot = false;
            }

            // si le mot est complet, on l'analyse
            if (finMot == true) {
            finMot = false; // on remet ca a False pour le prochain mot 
            //cout << motComplet << endl; // FLUSHER
                
                if (motComplet == "engrenage") {
                    while (finNbr == false && fichier.get(c)) {
                        if (isdigit(c) || c == '-') {
                            debutNbr = true;
                            nbrComplet += c;
                        } else if ((c == ' ' || c == '\n') && debutNbr == true) {
                            finNbr = true;
                            debutNbr = false;
                        } else if (c != ' ' && c != '\n') {      
                            cerr << "Fichier invalide, caracteres invalides" << endl;
                            exit(-1);
                        }
                    }
                    //cout << nbrComplet << " (engrenage)" << endl; // FLUSHER
                    int nombreDents = stoi(nbrComplet);
                    Engrenage * piece = 
                        new Engrenage("engrenage", nombreDents);
                    vecteur.push_back(piece);  
            
                } else if (motComplet == "vis") {
                    while (finNbr == false && fichier.get(c)) {
                        if (isdigit(c) || c == '-') {
                            debutNbr = true;
                            nbrComplet += c;
                        } else if ((c == ' ' || c == '\n') && debutNbr == true) {
                            finNbr = true;
                            debutNbr = false;
                        } else if (c != ' ' && c != '\n') {
                            cerr << "Fichier invalide, caracteres invalides" << endl;
                            exit(-1);
                        }
                    }
                    //cout << nbrComplet << " (vis)" << endl; // FLUSHER
                    int nombreSillons = stoi(nbrComplet);
                    Vis * piece = new Vis("vis", nombreSillons);
                    vecteur.push_back(piece);

                } else if (motComplet == "essieu") {
                    Essieu * piece = new Essieu("essieu");
                    vecteur.push_back(piece);
                } else if (motComplet == "direct") {
                    Direct * piece = new Direct("direct");
                    vecteur.push_back(piece);
                } else if (motComplet == "chaine") {
                    Chaine * piece = new Chaine("chaine");
                    vecteur.push_back(piece);
                } else {
                    cerr << "nom de piece invalide" << endl;
                    exit(-1);
                } 
                // on remet tout a zero pour le prochain mot
                motComplet = "";
                nbrComplet = "";
                finNbr = false;
            }
        }
        fichier.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier" << endl;
        exit(-1);
    }
    return vecteur;
} // Fin convertirFichierEnVecteur() 
        
void LectureFichier::validerDonnees(vector<Objet*> vecteur) {
    validerComposanteFin(vecteur);
    validerReglesFormationMecanisme(vecteur);
} 

void LectureFichier::validerComposanteFin(vector<Objet*> vecteur) {   
    int dernierePosition = vecteur.size() - 1;
    if (vecteur[dernierePosition]->typePiece != "composante") {
        cerr << "Fichier invalide, fini pas par une composante" << endl;
        exit(-1);
    }
}

void LectureFichier::validerReglesFormationMecanisme(vector<Objet*> vecteur) {
    for (int i = 0; i < vecteur.size(); ++i) {
        // alterne-t-on composante et lien? indices des composantes toujours impairs
        if (i % 2 == 1 && vecteur[i]->typePiece == "composante") {
            cerr << "Fichier invalide, on alterne pas lien et composante" << endl;
            exit(-1);
        }
                
        // TODO si meme msg erreur identique dans constantes, regrouper le corps des fonctions
        if (vecteur[i]->nom == "vis" && vecteur[i + 1] != nullptr && vecteur[i + 1]->nom != "direct") {
            cerr << "le lien suivant une vis doit etre direct" << endl;
            exit(-1);
        }
        if ((vecteur[i]->nom == "direct" || vecteur[i]->nom == "chaine") && vecteur[i + 1]->nom != "engrenage") {
            cerr << "un lien direct ou une chaine peut seulement etre suivi d'un engrenage" << endl;
            exit(-1);
        }
        if (vecteur[i]->nom == "direct" && vecteur[i - 1]->nom == "vis") {
            vecteur[i]->calculerEfficaciteDirectAvecVis(vecteur[i - 1]->nombreDentOuSillon);
        }
    }
}

double LectureFichier::calculerEfficaciteTotale(vector<Objet*> vecteur) {

    double efficaciteTotale = 0.0;
     
    for (int i = 0; i < vecteur.size(); ++i) {
        if (vecteur[i]->typePiece == "lien") {
            efficaciteTotale = 
                efficaciteTotale == 0 ? 
                vecteur[i]->efficacite : 
                efficaciteTotale * vecteur[i]->efficacite;  
        }    
    }
    return efficaciteTotale;
}
    // tests

    //for (int i = 0; i < vecteur.size(); ++i) {
    //    Objet* element = vecteur[i];
    //    cout << "nom : " << element->nom << endl;
    //    if (element->typePiece == "composante") {
    //        cout << "nombreDentOuSillon : " << element->nombreDentOuSillon << endl; 
    //    } else {
    //        cout << "efficacite : " << element->efficacite << endl;
    //    }
    //    cout << "\n" << endl;
    //}    

