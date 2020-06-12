#include "Composante.hpp"

class Vis : public Composante {
    // attribut de classe
    int _nombreSillon;
  
public:
    // constructeur
    Vis (int nombreSillon);
    // getter
    int getNombreSillon();
};
