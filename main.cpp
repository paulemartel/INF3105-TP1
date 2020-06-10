#include <iostream>
#include <string>
#include "Constantes.hpp"

//declaration de fonctions
double demandeDouble();


int main(int argc, const char** args){
    bool finProg = false;
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

        //verification si les deux valeurs sont du meme signe
        while(!(vitesseComposante >= 0 && couple >= 0) || (vitesseComposante < 0 && couple < 0)){

            std:cout << MSSG_ERR_MEME_SIGNE << std::endl;
            std::cout << MSSG_REQUETE_COUPLE << std::endl;
            couple = demandeDouble(); //marche pas??

        }




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
        std::cout << "Pas un double Veuillez entrer une nouvelle valeur" << std::endl;
        cin.clear();
        cin.ignore(100000, '\n');
    }

    return nombre;
}







