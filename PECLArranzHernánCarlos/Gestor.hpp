#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Gestor{
private:
	Pila pila;
	Cola colaGPU0;
	Cola colaGPU1;
	Cola colaGPU2;
	Cola colaGPU3;
	Lista listaNormal;
	Lista listaTiempoReal;
public:
	Gestor();  //Constructor
	~Gestor();  //Destructor
	
	 void genera12Procesos();                 
    void muestraProcesos();                   
    void borraProcesosPila();                 
    void encolarProcesos();                  
    void muestraProcesosGPUs0y1();            
    void muestraProcesosGPUs2y3();            
    void borraProcesosColas();                
    void enlistarProcesos();
	void muestraProcesosNormal();                 
    void muestraProcesosTiempoReal();        
    void buscarProcesos();                    
    void buscarProcesoPorNombreUsuario();     
    void eliminarProcesoPorPID();             
    void cambiarPrioridadProcesoPorPID();    
    void reiniciar();                         

};

#endif
