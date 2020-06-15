#include "Composante.hpp"

#include <string>
using namespace std;

class Vis : public Composante {
      
  
public:
    
    Vis (string nom, int nombreSillon, string typeObjet);
    
    int getNombreSillon();
};
