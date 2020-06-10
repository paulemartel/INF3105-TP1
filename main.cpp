#include <iostream>
#include <string>
#include "Constantes.hpp"

int main(int argc, const char** args){
    bool finProg = false;
    double vitesseComposante = 0;
    double couple = -1;
    std::string reponse("");


    while(!finProg){
        //lire et valider le fichier


        //demande de requetes a l'utilisateur
        bool finRequete = false;

        while(!finRequete){

            try{

                std::cout << MSSG_REQUETE_VITESSE << std::endl;
                std::cin >> vitesseComposante;  //gestion d'erreur?

                std::cout << MSSG_REQUETE_COUPLE << std::endl;
                std::cin >> couple;

                while(couple < 0){
                    std::cout << MSSG_ERR_COUPLE_INVALIDE << std::endl;
                    std::cout << MSSG_REQUETE_COUPLE << std::endl;
                    std::cin >> couple;
                }
                finRequete = true;
            } catch(std::exception e){
                std::cout << "Erreur mauvaise allocation" << std::endl;

            }    
        } 



        //nouvelle analyse
        std::cout << MSSG_QUESTION_CONTINUER << std::endl;
        std::cin >> reponse;
        if(reponse.compare("n") == 0){
            finProg = true;
        }



    }

}