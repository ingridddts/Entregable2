#ifndef ADTmap_H
#define ADTmap_H
#include <string> 

using namespace std;

class ADTmap{

public:
	virtual void insert(pair<string, int>)=0; //inserta par llave-valor
	virtual void erase(string)=0; // elimina un valor asociado a una llave
	virtual int at(string) = 0; //encontrar valor asociado a una llave
	virtual int size() = 0; //obtener cantidad de elementos
	virtual bool isempty() = 0; //verificar si está vacía
};

#endif
