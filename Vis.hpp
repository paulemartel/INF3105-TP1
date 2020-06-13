#include "Composante.hpp"

#include <string>
using namespace std;

class Vis : public Composante {
      
  
public:
    // constructeur
    Vis (string nom, int nombreSillon);
    // getter
    int getNombreSillon();
};
