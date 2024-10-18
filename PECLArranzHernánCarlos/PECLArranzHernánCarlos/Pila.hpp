#ifndef PILA_HPP
#defina PILA_HPP

#include "NodoPila.hpp"

class Pila{
public():
	Pila();
	~Pila();
	void insertar(Proceso* p);
	Proceso* extraer();
	Proceso* cima();
	void mostrar();
	void getLongitud();
	
private:
	pnodoPila ultimo;
	int longitud;
};

#endif
