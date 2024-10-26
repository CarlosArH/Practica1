#ifndef PROCESO_HPP
#define PROCESO_HPP

#include <iostream>

using namespace std;

class Proceso {
private:
    int pid;
    char usuario;
    bool estado; 
    int prioridad;
    bool tiempoReal; 
public:
    Proceso(int pid, char usuario, bool tiempoReal);
    ~Proceso();
    int getPID() const;
    char getUsuario() const;
    bool mostrar_proceso() const;
    int getPrioridad() const;
    bool esTiempoReal() const;
    void setEjecucion(bool estado);
    void setPrioridad(int nuevaPrioridad);
    void mostrar() const;
	int* GenerarPIDs() const;
};
#endif // PROCESO_HPP