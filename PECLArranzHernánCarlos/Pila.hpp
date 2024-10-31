#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila{
public:
	Pila();
	~Pila();
	void insertar(Proceso* p);
	Proceso* generarProceso(int usuarios, int* array, int i);
	void mostrarProcesos() const;
	Proceso* extraer();
	void vaciar() const;
	Proceso* cima() const;
	void mostrar() const;
	bool estaVacia() const;
	int getLongitud() const;
	
	
private:
	pnodoPila ultimo;
	int longitud;
};

#endif