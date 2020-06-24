#include "Vis.hpp"
#include "Constantes.hpp"
#include <iostream>

Vis::Vis (int const & nombreSillon) {
    
    if (nombreSillon % 1 != 0) {
        cerr << MSSG_ERR_DEVRAIT_SILLON << endl;
        exit(-1);
    } 
    if (nombreSillon >= NOMBRE_SILLON_MINIMUM 
            && nombreSillon <= NOMBRE_SILLON_MAXIMUM) {
        nombreDentOuSillon = nombreSillon;
    } else {
        cerr << MSSG_ERR_NOMBRE_SILLON << endl;
        exit(-1);
    }
    nom = "vis";
    typePiece = "composante";
}
