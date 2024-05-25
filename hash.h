#include "ADTmap.h"
#include <vector>
#include <string>

using namespace std;

struct nodo{
	struct nodo *izquierda; //hashing abierto
	struct nodo *derecha;
	string university; //uni a la que sigue el usuario - string
    int user_ID; //num identificador usuario - num
    string user_name; //nom usuario - dtring
    int numbertweets; // num tweets - num
    int friendsCount; //num de cuentas que sigue el usuario - num
    int followersCount; //num de seguidores - num
    //createdAt // fecha creación cuenta - fechs
};

class FuncionHash : public ADTmap {
private:
    vector<pair<string,int>> * arr;
	int n;
  
public:
    FuncionHash();
    ~FuncionHash();
    insert(pair<string, int> p); //inserta par llave-valor
	//erase(string str); // elimina un valor asociado a una llave
	//at(string str); //encontrar valor asociado a una llave
	//size(); //obtener cantidad de elementos
	//isempty(); //verificar si está vacía
};
