#ifndef LECTUREFICHIER_HPP_
#define LECTUREFICHIER_HPP_

/*
 * Lit le fichier entre en argument a la ligne de commande, puis
 * en extrait le mecanisme (composantes et liens) et les place
 * dans un vector.
 *
 * Auteures : Paule Martel et Gabrielle Poitras
 * Code permanent : 
 *     MARP16569700
 *     POIG16519008
 * Courriel : 
 *     martel.paule@courrier.uqam.ca
 *     poitras.gabrielle.2@courrier.uqam.ca
 * Cours : INF3105-30
 * Date : 2020-06-22
 */


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Engrenage.hpp"
#include "Vis.hpp" 
#include "Essieu.hpp"
#include "Direct.hpp"
#include "Chaine.hpp"
#include "Constantes.hpp"

using namespace std;

class LectureFichier {
    
    /**
     * Verifie si le fichier fourni en argument est vide, 
     * et, le cas echeant, met fin au programme.
     * 
     * @param fichier objet ifstream renfermant le fichier lu 
     *     par le programme
     */ 
    void estVide(ifstream& fichier);

    /**
     * Lit le fichier fourni et en analyse le contenu pour
     * degager le nombre de dents ou de sillons, selon le
     * nom de la composante, et creer un objet Engrenage ou Vis.
     * 
     * @param fichier objet ifstream renfermant le fichier lu
     *     par le programme
     * @param nom nom de la composante visee (Engrenage ou Vis)
     * @return pointeur d'Objet (Engrenage ou Vis)
     */ 
    Objet* creationComposante(ifstream& fichier, string const & nom);
       
    /**
     * Determine le type de mecanisme (composante ou lien) invalide
     * et affiche le message d'erreur qui convient.
     * 
     * @param vecteur liste des composantes et liens jusqu'a present 
     */ 
    void indiquerComposanteOuLienInvalide(vector<Objet*> const & vecteur);
       
    /**
     * Verifie si le vecteur se termine bel et bien par une composante.
     * 
     * @param vecteur liste complete des composantes et liens
     */ 
    void validerComposanteFin(vector<Objet*> const & vecteur);
       
    /**
     * Verifie si le mecanisme suit bel et bien les regles de formation.
     * 
     * @param vecteur liste complete des composantes et liens
     */ 
    void validerReglesFormationMecanisme(vector<Objet*> const & vecteur);   
    
public:
    string nomFichier;
       
    /**
     * Construit un objet LectureFichier.
     * 
     * @param fichierEntre nom du fichier lu par le programmme
     */ 
    LectureFichier(string const & fichierEntre);
       
    /**
     * Lit et analyse le fichier donne en argument pour construire
     * un vecteur renfermant chaque composante et lien du mecanisme,
     * avec toutes leurs caracteristiques, dans le meme ordre que
     * dans le fichier original.
     * 
     * @return vector renfermant des pointeurs d'Objet
     */ 
    vector<Objet*> convertirFichierEnVecteur();
       
    /**
     * Verifie si le vecteur remplit tous les criteres de validite.
     * 
     * @param vecteur liste complete des composantes et liens
     */ 
    void validerDonnees(vector<Objet*> const& vecteur);
};

#endif
