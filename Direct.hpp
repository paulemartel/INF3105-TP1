#include "Lien.hpp"

#include <string>
using namespace std;

class Direct : public Lien {
public:
    double efficacite;
    Direct(string nomPiece, string typeObjet);

};
