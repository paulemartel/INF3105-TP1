#include "Principale.hpp"

//declaration de fonctions
double demandeDouble();
bool memeSigne(double num1,double num2);
void analyseMouvement(double vitesseComposante, double couple, vector<Objet*> vecteur);
double calculR(Objet* composante1, Objet* lien, Objet* composante2);


int main(int argc, const char** args){
    bool finProg = false;
    bool coupleValide = true;
    double vitesseComposante = 0;
    double couple = 0;
    std::string reponse("");


    while(!finProg){
        //lire et valider le fichier


        //demande de requetes a l'utilisateur
        std::cout << MSSG_REQUETE_VITESSE << std::endl;
        vitesseComposante = demandeDouble();

        std::cout << MSSG_REQUETE_COUPLE << std::endl;
        couple = demandeDouble();
        coupleValide = memeSigne(vitesseComposante,couple);


        //verification si les deux valeurs sont du meme signe
        while(!coupleValide){

            std:cout << MSSG_ERR_MEME_SIGNE << std::endl;
            std::cout << MSSG_REQUETE_COUPLE << std::endl;
            couple = demandeDouble();
            coupleValide = memeSigne(vitesseComposante,couple);

        }

        //création d'un vecteur temporaire pour test
        vector<Objet*> vecteur;

        Vis * piece1 = new Vis("vis", 2);
        vecteur.push_back(piece1);

        Direct * piece2 = new Direct("direct");
        vecteur.push_back(piece2);

        Engrenage * piece3 = new Engrenage("engrenage", 10);
        vecteur.push_back(piece3);

        Chaine * piece4 = new Chaine("chaine");
        vecteur.push_back(piece4);

        Engrenage * piece5 = new Engrenage("engrenage", 20);
        vecteur.push_back(piece5);

        Essieu * piece6 = new Essieu("essieu");
        vecteur.push_back(piece6);

        Engrenage * piece7 = new Engrenage("engrenage", 10);
        vecteur.push_back(piece7);

        Direct * piece8 = new Direct("direct");
        vecteur.push_back(piece8);

        Engrenage * piece9 = new Engrenage("engrenage", 15);
        vecteur.push_back(piece9);

        analyseMouvement(vitesseComposante,couple,vecteur);












        //nouvelle analyse
        std::cout << MSSG_QUESTION_CONTINUER << std::endl;
        std::cin >> reponse;
        if(reponse.compare("n") == 0){
            finProg = true;
        }
    }
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








