#include "Lista.hpp"

Lista::Lista(){
	this->cabeza = nullptr;
	this->longitud = 0;
}
Lista::~Lista(){
	NodoLista* actual = this->cabeza;
	while (actual != nullptr){
		NodoLista* siguiente = actual->siguiente;
		delete actual->p;
		delete actual;
		actual = siguiente;
	}
}