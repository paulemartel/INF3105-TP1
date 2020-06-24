#include "LectureFichier.hpp"

LectureFichier::LectureFichier(string const & fichierEntre) {
    nomFichier = fichierEntre;
}

void LectureFichier::estVide(ifstream& fichier) {
    if (fichier.peek() == EOF) {
        cerr << MSSG_ERR_UNE_COMPOSANTE_MINIMUM << endl;
        exit(-1);
    }
}

Objet* LectureFichier::creationComposante(ifstream& fichier, 
        string const & nom) {
    char c;
    int finNbr = false;
    int debutNbr = false;
    string nbrComplet = "";
    Objet* piece;

    while (finNbr == false && fichier.get(c)) {
        if (isdigit(c) || c == '-') {
            debutNbr = true;
            nbrComplet += c;
        } else if ((c == ' ' || c == '\n')
                && debutNbr == true) {
            finNbr = true;
            debutNbr = false;
        } else if (c != ' ' && c != '\n') {
            if (nom == "engrenage") {
                cerr << MSSG_ERR_DEVRAIT_NOMBRE_DENT << endl;
            } else {
                cerr << MSSG_ERR_DEVRAIT_SILLON << endl;
            }
            exit(-1);
        }
    }

    int nombreDentsOuSillons = stoi(nbrComplet);

    if (nom == "engrenage") {
        piece = new Engrenage(nombreDentsOuSillons);
    } else {
        piece = new Vis(nombreDentsOuSillons);
    }
    return piece;
}

void LectureFichier::indiquerComposanteOuLienInvalide(
        vector<Objet*> const & vecteur) {
    if (!vecteur.empty() && vecteur[vecteur.size() - 1]->typePiece 
            == "composante") {
        cerr << MSSG_ERR_LIEN_INVALIDE << endl;
    } else {
        cerr << MSSG_ERR_COMPOSANTE_INVALIDE << endl;
    }
    exit(-1);
}

vector<Objet*> LectureFichier::convertirFichierEnVecteur() {
    ifstream fichier (nomFichier);
    vector<Objet*> vecteur;

    if (fichier.is_open()) {

        estVide(fichier);

        char c;
        bool debutMot;
        bool debutNbr;
        bool finMot = false;
        bool finNbr;
        string motComplet = "";
        string nbrComplet = "";

        while (fichier.get(c)) {
            Objet * piece;

            if (c != ' ' && c != '\n') {
                debutMot = true;
                motComplet += c;
            } else if (debutMot == true && (c == ' ' || c == '\n')) {
                finMot = true;
                debutMot = false;
            }

            if (finMot == true) {
                finMot = false;

                if (motComplet == "engrenage") {
                    piece = creationComposante(fichier, "engrenage");               
                
                } else if (motComplet == "vis") {
                    piece = creationComposante(fichier, "vis");

                } else if (motComplet == "essieu") {
                    piece = new Essieu();
               
                } else if (motComplet == "direct") {
                    piece = new Direct();
               
                } else if (motComplet == "chaine") {
                    piece = new Chaine();
                    
                } else {
                    indiquerComposanteOuLienInvalide(vecteur);
                }
                vecteur.push_back(piece);
                motComplet = "";
                nbrComplet = "";
                finNbr = false;
            }
        }
        fichier.close();
    } else {
        cerr << MSSG_ERR_FICHIER_INEXISTANT << endl;
        exit(-1);
    }

    validerDonnees(vecteur);

    return vecteur;
} 

void LectureFichier::validerDonnees(vector<Objet*> const & vecteur) {
    validerComposanteFin(vecteur);
    validerReglesFormationMecanisme(vecteur);
}

void LectureFichier::validerComposanteFin(vector<Objet*> const & vecteur) {
    int dernierePosition = vecteur.size() - 1;
    if (vecteur[dernierePosition]->typePiece != "composante") {
        string nomLien = vecteur[dernierePosition]->nom;

        if (nomLien == "essieu") {
            cerr << MSSG_ERR_COMPOSANTE_APRES_ESSIEU << endl;
        } else if (nomLien == "direct") {
            cerr << MSSG_ERR_COMPOSANTE_APRES_DIRECT << endl;
        } else {
            cerr << MSSG_ERR_COMPOSANTE_APRES_CHAINE << endl;
        }
        exit(-1);
    }
}

void LectureFichier::validerReglesFormationMecanisme(
        vector<Objet*> const & vecteur) {
    for (int i = 0; i < vecteur.size(); ++i) {
        
        if (i % 2 == 1 && vecteur[i]->typePiece == "composante") {
            cerr << MSSG_ERR_ALTERNANCE_COMPOSANTE_LIEN << endl;
            exit(-1);
        }
        
        if (vecteur[i]->nom == "vis" && i != (vecteur.size() - 1)
                && vecteur[i + 1]->nom != "direct") {
            cerr << MSSG_ERR_SEULEMENT_DIRECT << endl;
            exit(-1);
        }

        if (vecteur[i]->nom == "direct" && vecteur[i + 1]->nom 
                != "engrenage") {
            cerr << MSSG_ERR_SEULEMENT_ENGRENAGE_DIRECT << endl;
            exit(-1);
        }
        if (vecteur[i]->nom == "chaine" && vecteur[i + 1]->nom 
                != "engrenage") {
            cerr << MSSG_ERR_SEULEMENT_ENGRENAGE_CHAINE << endl;
            exit(-1);
        }
        if (vecteur[i]->nom == "direct" && vecteur[i - 1]->nom == "vis") {
            vecteur[i]->calculerEfficaciteDirectAvecVis(
                vecteur[i - 1]->nombreDentOuSillon);
        }
    }
}
