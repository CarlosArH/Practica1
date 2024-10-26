#include "Proceso.hpp"
#include <algorithm>

Proceso::Proceso(int pid, string usuario, bool tiempoReal) {
    this->pid = pid;
    this->usuario = usuario;
    this->estado = false; // Inicialmente parado
    this->tiempoReal = tiempoReal; // 0 = normal, 1 = tiempo real
    this->prioridad = tiempoReal ? rand() % 100 : 120 + (rand() % 39) - 19;
}

Proceso::~Proceso() {
    // Destructor
}

int Proceso::getPID() const {
    return pid;
}

string Proceso::getUsuario() const {
    return usuario;
}

bool Proceso::mostrar_proceso() const {
    return estado;
}

int Proceso::getPrioridad() const {
    return prioridad;
}

bool Proceso::esTiempoReal() const {
    return tiempoReal;
}

void Proceso::setEjecucion(bool estado) {
    this->estado = estado;
}

void Proceso::setPrioridad(int nuevaPrioridad) {
    this->prioridad = nuevaPrioridad;
}

void Proceso::mostrar() const {
    cout << "PID: " << pid << ", Usuario: " << usuario << ", Estado: " << (estado ? "Ejecución" : "Parado")
         << ", Prioridad: " << prioridad << ", Tipo: " << (tiempoReal ? "Tiempo Real" : "Normal") << endl;
}
