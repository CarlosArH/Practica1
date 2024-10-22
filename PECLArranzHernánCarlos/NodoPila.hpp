#include <iostream>
#include "Proceso.hpp"
using namespace std;

class NodoPila{
public:
	NodoPila(Proceso* p, NodoPila* sig = NULL);
	~NodoPila();
	
private:
	Proceso* p;
	NodoPila* siguiente;
	friend class Pila;
};

typedef NodoPila* pnodoPila;
