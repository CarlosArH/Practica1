#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"
#include <iostream>
#include <string>

class Lista {
public:
	Lista();
	~Lista();
	
	void insertar(Proceso* proceso);
	void mostrar();
	NodoLista* buscarPorPID(int pid);
	void eliminarPorPID(int pid);
	void cambiarPrioridadPorPID(int pid, int nuevaPrioridad);
	
private:
	pnodoLista cabeza;
	int longitud;
};

#endif
