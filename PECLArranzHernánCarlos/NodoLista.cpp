#include "NodoLista.hpp"

NodoLista::NodoLista(Proceso* p, NodoLista* sig)
{
	Proceso* proceso = p;
	siguiente = sig;
}
NodoLista::~NodoLista()
{
}