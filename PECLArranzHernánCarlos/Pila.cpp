#include "Pila.hpp"

Pila::Pila()
{
	ultimo = NULL;
	longitud = 0;
}

void Pila::insertar(Proceso* p)
{
	pnodoPila nuevo;
	nuevo = new NodoPila(p, ultimo);
	ultimo = nuevo;
	longitud++;
}

Proceso* Pila:: extraer()
{
	pnodoPila nodo;
	Proceso* p;
	if(!ultimo)
		return NULL;
	nodo = ultimo;
	ultimo = nodo->siguiente;
	p = nodo->proceso;
	longitud--;
	delete nodo;
	return p
}

Proceso* Pila::cima()
{
	if(!ultimo)
		return NULL;
	return ultimo->proceso;
}

void Pila::mostrar()
{
	pnodoPila aux = ultimo;
	cout << "\tEl contenido de la pila es: " << endl;
	while(aux) {
		aux->proceso->mostrar();
		aux = aux->siguiente;
	}
	cout << endl;
}

int Pila::getLongitud()
{
	return this->longitud;
}

Pila::~Pila()
{
	pnodoPila aux;
	while(ultimo){
		aux = ultimo;
		ultimo = ultimo->siguiente;
		delete aux;
	}
}