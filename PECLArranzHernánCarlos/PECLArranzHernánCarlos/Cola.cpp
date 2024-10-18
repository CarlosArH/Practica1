#include "Cola.hpp"

Cola::Cola()
{
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

void Cola::insertar(Proceso* p)
{
	pnodoCola nuevo;
	nuevo = new NodoCola(p, ultimo);
	if(ultimo)
		ultimo->siguiente = nuevo;
	
	ultimo = nuevo;
	
	if(!primero)
		primero = nuevo;
	longitud++;
}

void Cola::mostrar()
{
	pnodoCola aux = primero;
	cout << "\tEl contenido de la cola es: ";
	while(aux) {
		cout <<"-> " << aux->proceso;
		aux = aux->siguiente;
	}
	cout << endl;
}

Proceso* Cola::eliminar()
{
	pnodoCola nodo;
	Proceso* p;
	nodo = primero;
	if(!nodo)
		return 0;
	primero = nodo->siguiente;
	p = nodo->proceso;
	delete nodo;
	if(!primero)
		ultimo = NULL;
	longitud--;
	return p;
}

Proceso* Cola ::verPrimero(){
	return primero->proceso;
}

Cola::~Cola()
{
	while(primero)
		eliminar();
}