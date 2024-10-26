#include "Lista.hpp"

Lista::Lista() {
    cabeza = nullptr;
    longitud = 0;
}

Lista::~Lista() {
    while (cabeza != nullptr) {
        NodoLista* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void Lista::insertar(Proceso* proceso) {
    NodoLista* nuevoNodo = new NodoLista(proceso);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
    longitud++;
}

void Lista::mostrar() const {
    NodoLista* actual = cabeza;
    while (actual != nullptr) {
        actual->proceso->mostrar();
        actual = actual->siguiente;
    }
}

Proceso* Lista::buscarPorPID(int pid) const {
    NodoLista* actual = cabeza;
    while (actual != nullptr) {
        if (actual->proceso->getPID() == pid) {
            return actual->proceso;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Lista::eliminarPorPID(int pid) {
    NodoLista* actual = cabeza;
    NodoLista* anterior = nullptr;
    while (actual != nullptr && actual->proceso->getPID() != pid) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual != nullptr) {
        if (anterior == nullptr) {
            cabeza = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        longitud--;
    }
}

void Lista::cambiarPrioridadPorPID(int pid, int nuevaPrioridad) {
    Proceso* proceso = buscarPorPID(pid);
    if (proceso != nullptr) {
        proceso->setPrioridad(nuevaPrioridad);
    }
}

int Lista::getLongitud() const {
    return longitud;
}