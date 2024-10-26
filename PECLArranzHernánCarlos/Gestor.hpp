#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Proceso.hpp"

#include <iostream>
#include <cstdlib>

class Gestor {
private:
    Pila pila;
    Cola colas[4];
    Lista listaNormal;
    Lista listaTiempoReal;
	int pidCounter;
	int usuarioCounter;
	int* arrayPIDs;

public:
    void genera12Procesos();
    void muestraProcesos() const;
    void borraProcesosPila();
    void encolarProcesos();
    void muestraProcesosGPUs0y1() const;
    void muestraProcesosGPUs2y3() const;
    void borraProcesosColas();
    void enlistarProcesos();
    void muestraProcesosNormal() const;
    void muestraProcesosTiempoReal() const;
    void buscarProcesos() const;
    void buscarProcesoPorNombreUsuario() const;
    void eliminarProcesoPorPID();
    void cambiarPrioridadProcesoPorPID();
    void reiniciar();

    // Métodos adicionales para adaptarse al main
    int ProcesosEnPila() const;
    int ProcesosEnGPU0() const;
    int ProcesosEnGPU1() const;
    int ProcesosEnGPU2() const;
    int ProcesosEnGPU3() const;
    int ProcesosEnListaNormal() const;
    int ProcesosEnListaTiempoReal() const;
    int ProcesosEnArbol() const;
};

#endif // GESTOR_HPP
