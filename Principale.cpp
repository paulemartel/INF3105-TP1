#include "Principale.hpp"

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
        // integrer le fichier a lire
        LectureFichier* fichier = new LectureFichier("tests/testv5.txt");
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
        // calcul de l'efficacite totale (je le mets la en attendant)
        double efficaciteTotale = calculerEfficaciteTotale(vecteur);


        //nouvelle analyse
        std::cout << MSSG_QUESTION_CONTINUER << std::endl;
        std::cin >> reponse;
        if(reponse.compare("n") == 0){
            finProg = true;
        }
    
    }
}

double calculerEfficaciteTotale(vector<Objet*> vecteur) {

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


/**
Fonction qui se charge de s'assurer que la valeur entree en input par l'utilisateur
est bel et bien un double. Si ce n'est pas le cas, demande a l'utilisateur d'entrer
une nouvelle valeur
retourne un double
**/
double demandeDouble(){
    double nombre;
    while(!(std::cin >> nombre)){
        std::cout << "Pas un double Veuillez entrer"
        << "une nouvelle valeur" << std::endl;
        cin.clear();
        cin.ignore(100000, '\n');
    }

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

    //affichage V0 et C0
    int nombre = 0;


    for(int i = 0; i<vecteur.size(); i=i+2 ){
        //affichage
        //TODO : Il reste juste a trouver l'efficacite totale
        //Et multiplier cette valeur ici
        std::cout << "V"<< nombre <<"=" 
        << vitesseInitiale <<" C" 
        << nombre << "=" << coupleIninitial << std::endl;

        ++nombre;

        if(i != vecteur.size()-1){
        //calcul de r
        Objet* composante1 = vecteur[i];
        Objet* lien = vecteur[i+1];
        Objet* composante2 = vecteur[i+2];

        constanteR = calculR(composante1,lien,composante2);

        std::cout << "VALEUR DE R : " << constanteR << std::endl;

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



