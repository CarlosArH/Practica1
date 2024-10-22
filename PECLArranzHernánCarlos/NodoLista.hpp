#include <iostream>
#include "Proceso.hpp"
using namespace std;

class NodoLista{
public:
	NodoLista(Proceso* p, NodoLista* sig = NULL);
	~NodoLista();
	
private:
	Proceso* p;
	NodoLista* siguiente;
	friend class Lista;
};

typedef NodoLista* pnodoLista;