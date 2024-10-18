#include "Proceso.hpp"

Proceso::Proceso() {
    this->pid = pid;
    this->usuario = usuario;
    this->estado = false;
    this->tiempoReal = tiempoReal;
    this->prioridad = tiempoReal ? rand() % 100 : 120 + (rand() % 39) - 19;
}
Proceso::~Proceso() {
    // Destructorh
}
int Proceso::getPID() const {
    return pid;
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
    cout << "PID: " << pid << ", Usuario: " << usuario << ", Estado: " << (estado ? "Ejecución" : "Parado")<< ", Prioridad: " << prioridad << ", Tipo: " << (tiempoReal ? "Tiempo Real" : "Normal") << endl;
}