#include "Gestor.hpp"
#include <iostream>
#include <cstdlib>

void Gestor::generarProcesos(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int pid = 300 + rand() % 1000;
        std::string usuario = "usuario" + std::to_string(rand() % 100);
        bool tiempoReal = rand() % 2;
        Proceso* proceso = new Proceso(pid, usuario, tiempoReal);
        pila.apilar(proceso);
    }
}

void Gestor::mostrarPila() const {
    pila.mostrar();
}

void Gestor::vaciarPila() {
    while (!pila.estaVacia()) {
        pila.desapilar();
    }
}

void Gestor::moverProcesosAColas() {
    while (!pila.estaVacia()) {
        Proceso* proceso = pila.desapilar();
        int indiceCola = proceso->esTiempoReal() ? (colas.estaVacia() ? 2 : 3) : (colas.estaVacia() ? 0 : 1);
        colas[indiceCola].encolar(proceso);
    }
}

void Gestor::mostrarColas() const {
    for (int i = 0; i < 4; i++) {
        std::cout << "Cola " << i << ":" << std::endl;
        colas[i].mostrar();
    }
}

void Gestor::vaciarColas() {
    for (int i = 0; i < 4; i++) {
        while (!colas[i].estaVacia()) {
            colas[i].desencolar();
        }
    }
}

void Gestor::moverProcesosAListas() {
    for (int i = 0; i < 4; i++) {
        while (!colas[i].estaVacia()) {
            Proceso* proceso = colas[i].desencolar();
            if (i < 2) {
                listaNormal.insertar(proceso);
            } else {
                listaTiempoReal.insertar(proceso);
            }
        }
    }
}

void Gestor::mostrarListas() const {
    std::cout << "Lista Normal:" << std::endl;
    listaNormal.mostrar();
    std::cout << "Lista Tiempo Real:" << std::endl;
    listaTiempoReal.mostrar();
}