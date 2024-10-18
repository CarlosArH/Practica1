#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
public:
	Lista();
	~Lista();
	void insertar(Proceso* proceso);
	Proceso* extraer();
	void vaciar();
	
private:
	pnodoLista
};

#endif
