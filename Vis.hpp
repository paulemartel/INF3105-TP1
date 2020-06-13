#include "Composante.hpp"

#include <string>
using namespace std;

class Vis : public Composante {
    // attribut de classe
    int _nombreSillon;
  
public:
    // constructeur
    Vis (int nombreSillon);
    // getter
    int getNombreSillon();
};
