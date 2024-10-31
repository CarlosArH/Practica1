#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola{
public():
	Cola();
	~Cola();
	
	void insertar(Proceso* p);
	Proceso* eliminar();
	void mostrar();
	Proceso* verPrimero();
	void 
	
private:
	pnodoCola primero, ultimo;
	int longitud;
};

#endif