#include <iostream>
#include <string>
#include "Constantes.hpp"

//declaration de fonctions
double demandeDouble();
bool memeSigne(double num1,double num2);


int main(int argc, const char** args){
    bool finProg = false;
    bool coupleValide = true;
    double vitesseComposante = 0;
    double couple = 0;
    std::string reponse("");
    std::cout << "HELLLLOOOOOO" << std::endl;


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
/**
Fonction qui vérifie si deux doubles est du meme signe
return true si c'est le cas sinon false
**/
bool memeSigne(double num1, double num2){

    return ((num1 >= 0 && num2 >= 0) 
        || (num1 < 0 && num2 < 0));

}








