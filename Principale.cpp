#include <iostream>
#include <string>
#include "Constantes.hpp"
#include <vector>
#include "LectureFichier.hpp"

using namespace std;


//declaration de fonctions
double demandeDouble();
bool memeSigne(double num1,double num2);
void analyseMouvement(double vitesseComposante, double couple, vector<Objet*> vecteur);
double calculR(Objet* composante1, Objet* lien, Objet* composante2);
double calculerEfficaciteTotale(vector<Objet*> vecteur);

int main(int argc, const char * argv []){
    bool finProg = false;
    bool coupleValide = true;
    double vitesseComposante = 0;
    double couple = 0;
    std::string reponse("");


    while(!finProg){
        // on verifie si un fichier a ete indique en ligne de commande
        if (argc <= 1) {
            cerr << MSSG_ERR_MANQUE_FICHIER_ARGUMENT << endl;
            exit(-1); 
        }
        // integrer le fichier a lire
        LectureFichier* fichier = new LectureFichier(argv[1]);
        // valider le fichier et creer le vecteur du mecanisme 
        vector<Objet*> vecteur = fichier->convertirFichierEnVecteur();
        
        //demande de requetes a l'utilisateur
        std::cout << MSSG_REQUETE_VITESSE << std::endl;
        vitesseComposante = demandeDouble();

        std::cout << MSSG_REQUETE_COUPLE << std::endl;
        couple = demandeDouble();
        coupleValide = memeSigne(vitesseComposante,couple);


        //verification si les deux valeurs sont du meme signe
        while(!coupleValide){

            cout << MSSG_ERR_MEME_SIGNE << std::endl;
            std::cout << MSSG_REQUETE_COUPLE << std::endl;
            couple = demandeDouble();
            coupleValide = memeSigne(vitesseComposante,couple);

        }

        analyseMouvement(vitesseComposante,couple,vecteur);

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

        //nouvelle analyse
        std::cout << MSSG_QUESTION_CONTINUER << std::endl;
        std::cin >> reponse;
        if(reponse.compare("n") == 0){
            finProg = true;
        }
    
    }
}

double calculerEfficaciteTotale(vector<Objet*> vecteur) {

    double efficaciteTotale = 1.0;

    for (int i = 0; i < vecteur.size(); ++i) {
        if (vecteur[i]->typePiece == "lien") {
            efficaciteTotale =
                efficaciteTotale == 1.0 ?
                vecteur[i]->efficacite :
                efficaciteTotale * vecteur[i]->efficacite;
        }
    }
    return efficaciteTotale;
}


/**
Fonction qui se charge de s'assurer que la valeur entree en input par l'utilisateur
est bel et bien un double. Si ce n'est pas le cas, demande a l'utilisateur d'entrer
une nouvelle valeur
retourne un double
**/

double demandeDouble(){
    double nombre;
    bool valide;

    do{
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
            cout << MSSG_ERR_REQUETE_PAS_DOUBLE << endl;
        }
        
    } while (!valide);


    return nombre;
}

/**
Fonction qui vérifie si deux doubles est du meme signe
return true si c'est le cas sinon false
**/
bool memeSigne(double num1, double num2){

    return ((num1 >= 0 && num2 >= 0) 
        || (num1 < 0 && num2 < 0));

}

void analyseMouvement(double vitesseComposante, double couple
    , vector<Objet*> vecteur){
    double vitesseInitiale = vitesseComposante;
    double vitesseProchain = 0;

    double coupleIninitial = couple;
    double coupleProchain  =0;

    double constanteR = 0;
    double efficaciteTot = calculerEfficaciteTotale(vecteur);

    int nombre = 0;


    for(int i = 0; i<vecteur.size(); i=i+2 ){

        //affichage des resultats
        cout << "V"<< nombre <<"=" 
        << vitesseInitiale * efficaciteTot <<" C" 
        << nombre << "=" << coupleIninitial * efficaciteTot << endl;

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



