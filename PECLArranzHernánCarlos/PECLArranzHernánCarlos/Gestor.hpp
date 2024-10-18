#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Gestor{
private:
	Pila pila;
	Cola colas;
	Lista listaNormal;
	Lista listaTiempoReal;
public:
	void generarProcesos(int cantidad);
	void mostrarPila() const;
	void vaciarPila();
	void moverProcesosACOlas();
	void mostrarColas() const;
	void vaciarColas();
	void moverProcesosAListas();
	void mostrarListas();
};

#endif
