#include <iostream>
#include <string>
#include <vector>
#include "Constantes.hpp"
#include "LectureFichier.hpp"

using namespace std;


//declaration de fonctions
double demandeDouble(string mssgErreur, string mssgRequete);
bool memeSigne(double num1,double num2);
void analyseMouvement(double vitesseComposante, double couple, 
    vector<Objet*> vecteur);
double calculR(Objet* composante1, Objet* lien, Objet* composante2);
double calculerEfficaciteTotale(vector<Objet*> vecteur);

int main(int argc, const char * argv []){
    bool finProg = false;
    bool coupleValide = true;
    double vitesseComposante = 0;
    double couple = 0;
    string reponse("");

    while(!finProg){
        //on verifie si un fichier a ete indique en ligne de commande
        if (argc <= 1) {
            cerr << MSSG_ERR_MANQUE_FICHIER_ARGUMENT << endl;
            exit(-1); 
        }
        
        LectureFichier* fichier = new LectureFichier(argv[1]);
        
        vector<Objet*> vecteur = fichier->convertirFichierEnVecteur();
        
        //demande de requetes a l'utilisateur
        cout << MSSG_REQUETE_VITESSE << ESPACE_DE_FIN;
        vitesseComposante = demandeDouble(MSSG_ERR_VITESSE_INVALIDE, 
            MSSG_REQUETE_VITESSE);

        cout << MSSG_REQUETE_COUPLE << ESPACE_DE_FIN;
        couple = demandeDouble(MSSG_ERR_COUPLE_INVALIDE, 
            MSSG_REQUETE_COUPLE);
        coupleValide = memeSigne(vitesseComposante,couple);

        //verification si les deux valeurs sont du meme signe
        while(!coupleValide){

            cout << MSSG_ERR_MEME_SIGNE << endl;
            cout << MSSG_REQUETE_COUPLE << ESPACE_DE_FIN;
            couple = demandeDouble(MSSG_ERR_MEME_SIGNE,
                MSSG_REQUETE_COUPLE);
            coupleValide = memeSigne(vitesseComposante,couple);
        }

        analyseMouvement(vitesseComposante,couple,vecteur);

        //nouvelle analyse
        cout << MSSG_QUESTION_CONTINUER << ESPACE_DE_FIN;
        cin >> reponse;
        if(reponse.compare("n") == 0){
            finProg = true;
        }
    }
}

/**
 * Fonction qui calcule l'efficacite totale.
 * 
 * @param vecteur vecteur de liens et composantes
 * @return l'efficacite totale
**/
double calculerEfficaciteTotale(vector<Objet*> vecteur) {

    double efficaciteTotale = 1.0;

    for (int i = 0; i < vecteur.size(); ++i) {
        if (vecteur[i]->typePiece == "lien") {
            efficaciteTotale = efficaciteTotale == 1.0 ?
                vecteur[i]->efficacite :
                efficaciteTotale * vecteur[i]->efficacite;
        }
    }
    return efficaciteTotale;
}

/**
 * Se charge de s'assurer que la valeur entree 
 * en input par l'utilisateur est bel et bien un double. 
 * Si ce n'est pas le cas, demande a l'utilisateur d'entrer une 
 * nouvelle valeur.
 * 
 * @param mssgErreur message d'erreur qui s'affiche
 * @param mssgRequete nouvelle requete
 * @return un double
**/

double demandeDouble(string mssgErreur, string mssgRequete){
    double nombre;
    bool valide;

    do {
        valide = true;
        cin >> nombre;
        if(!cin) {
            valide = false;
            cin.clear();
            cin.ignore(1000000, '\n');
        } else {
            string temp;
            getline(cin,temp);
            if(temp.find_first_not_of(" ") != string::npos){
                valide = false;
            }
        }
        if(!valide){
            cout << mssgErreur << endl;
            cout << mssgRequete << ESPACE_DE_FIN;
        }
        
    } while (!valide);

    return nombre;
}

/**
 * Verifie si deux doubles sont du meme signe.
 * 
 * @param num1 premier double entre par l'utilisateur
 * @param num2 deuxieme double entre par l'utilisateur
 * @return true si c'est le cas sinon false
**/
bool memeSigne(double num1, double num2){

    return ((num1 >= 0 && num2 >= 0) || (num1 < 0 && num2 < 0));
}

/**
 * Fait tous les calcul par rapport a l'analyse
 * du mouvement et affiche a l'ecran les resultats multiplies
 * par l'efficacite totale.
 * 
 * @param vitesseComposante vitesse de la composante
 * @param couple valeur du couple
 * @param vecteur liste des composantes et des liens
**/
void analyseMouvement(double vitesseComposante, double couple,
        vector<Objet*> vecteur){
    double vitesseInitiale = vitesseComposante;
    double vitesseProchain = 0;

    double coupleIninitial = couple;
    double coupleProchain  = 0;

    double constanteR = 0;
    double efficaciteTot = calculerEfficaciteTotale(vecteur);

    int nombre = 0;

    for(int i = 0; i<vecteur.size(); i=i+2 ){

        //affichage des resultats
        cout << "V"<< nombre <<" = " 
        << vitesseInitiale * efficaciteTot << "," <<" C" 
        << nombre << " = " << coupleIninitial * efficaciteTot << endl;

        ++nombre;

        if(i != vecteur.size()-1){
        //calcul de r
        Objet* composante1 = vecteur[i];
        Objet* lien = vecteur[i+1];
        Objet* composante2 = vecteur[i+2];

        constanteR = calculR(composante1,lien,composante2);

        //trouver vitesseProchain
        vitesseProchain = vitesseInitiale/constanteR;

        //trouver coupleProchain
        coupleProchain = coupleIninitial * constanteR;

        vitesseInitiale = vitesseProchain;
        coupleIninitial = coupleProchain;
        }
    }
}

/**
 * Calcule la valeur de la constante R.
 * 
 * @param composante1 le 1er objet
 * @param lien le lien entre les deux objets
 * @param composante2 le 2eme objet 
**/
double calculR(Objet* composante1, Objet* lien, Objet* composante2){
    double constanteR = 0;
    if(lien->nom == "essieu"){
        constanteR = 1;

    } else if(lien->nom == "direct" 
        && composante1->nom == "engrenage" 
        && composante2->nom == "engrenage"){

        constanteR = -1*(double)(composante2->nombreDentOuSillon)
        /(composante1->nombreDentOuSillon);

    } else if(lien->nom == "direct" 
        && composante1->nom == "vis" 
        && composante2->nom == "engrenage"){

        constanteR = (double)(composante2->nombreDentOuSillon)
        /(composante1->nombreDentOuSillon);
    } else if(lien->nom == "chaine" 
        && composante1->nom == "engrenage" 
        && composante2->nom =="engrenage"){

        constanteR = (double)(composante2->nombreDentOuSillon)
        /(composante1->nombreDentOuSillon);
    }

    return constanteR;
}
