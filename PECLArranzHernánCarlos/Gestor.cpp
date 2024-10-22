#include "Gestor.hpp"

Gestor:Gestor(Pila pila, Cola colaGPU0, Cola colaGPU1, Cola colaGPU2, Cola colaGPU3, Lista listaNormal, Lista listaTiempoReal){
	this->pila = Pila();
	this->colaGPU0 = Cola();
	this->colaGPU1 = Cola();
	this->colaGPU2 = Cola();
	this->colaGPU3 = Cola();
	this->listaNormal = Lista();
	this->listaTiempoReal = Lista();
}

Gestor:~Gestor(){
	
}

void Gestor::genera12Procesos()
{
	for(int i = 0; i < 12; ++i){
		Proceso* nuevoProceso = new Proceso();
		pila.insertar(nuevoProceso);
	}
}

void Gestor::muestraProcesos(){
	pila.mostrar();
}

void Gestor::borraProcesosPila(){
	while (pila.extraer() != nullptr);
}

void Gestor::encolarProcesos(){
	while(Proceso* proceso = pila.extraer()){
		if (proceso->esTiempoReal()){
			if(colaGPU2.getLongitud() <= colaGPU3.getLongitud()){
				colaGPU2.encolar(proceso);
			} else{
				colaGPU3.encolar(proceso);
			}
		}
		else{
			if(colaGPU0.getLongitud() <= colaGPU1.getLongitud()){
				colaGPU0.encolar(proceso);
			} else{
				colaGPU1.encolar(proceso);
			}
		}
	}
}

void Gestor::muestraProcesosGPUs0y1(){
	std::cout << "GPU 0:" << std::endl;
	colaGPU0.mostrar();
	std::cout << "GPU 1:" << std::endl;
	colaGPU1.mostrar();
}

void Gestor::muestraProcesosGPUs2y3(){
	std::cout << "GPU 2:" << std::endl;
	colaGPU2.mostrar();
	std::cout << "GPU 3:" << std::endl;
	colaGPU3.mostrar();
}

void Gestor::borraProcesosCola(){
	while(colaGPU0.extraer() != nullptr);
	while(colaGPU1.extraer() != nullptr);
	while(colaGPU2.extraer() != nullptr);
	while(colaGPU3.extraer() != nullptr);
}

Gestor::enlistarProcesos(){
	while(Proceso* proceso = colaGPU0.extraer()){
		listaNormal.insertar(proceso);
		proceso->setEstado(true);
	}
	while(Proceso* proceso = colaGPU1.extraer()){
		listaNormal.insertar(proceso);
		proceso->setEstado(true);
	}
	while(Proceso* proceso = colaGPU2.extraer()){
		listaTiempoReal.insertar(proceso);
		proceso->setEstado(true);
	}
	while(Proceso* proceso = colaGPU3.extraer()){
		listaTiempoReal.insertar(proceso);
		proceso->setEstado(true);
	}
}

void Gestor::muestraProcesosNormal(){
	listaNormal.mostrar();
}

void Gestor::muestraProcesosTiempoReal(){
	listaTiempoReal.mostrar();
}

void Gestor::buscarProcesos(){
	Proceso* procesoMenorPrioridadNormal = listaNormal.buscarMenorPrioridad();
	Proceso* procesoMayorPrioridadTiempoReal = listaTiempoReal.buscarMayorPrioridad();
	
	if (procesoMenorPrioridadNormal != nullptr){
		std::cout << "Proceso normal con menor prioridad: " << std::endl;
		procesoMenorPrioridadNormal->mostrar();
	}
	if (procesoMayorPrioridadTiempoReal != nullptr){
		std::cout << "Proceso normal con mayor prioridad: " << std::endl;
		procesoMayorPrioridadTiempoReal->mostrar();
	}
}

void Gestor::buscarProcesoPorNombreUsuario(){
	std::string nombreUsuario;
	std::cout << "Ingrese el nombre del usuario: ";
	std::cin >> nombreUsuario;
	
	listaNormal.buscarPorUsuario(nombreUsuario);
	listaTiempoReal.buscarPorUsuario(nombreUsuario);
}

void Gestor::eliminarProcesoPorPID(){
	int pid;
	std::cout << "Introduce PID: "
	std::cin >> pid;
	
	if (listaNormal.eliminarPorPID(pid) || listaTiempoReal.eliminarPorPID(pid)){
		std::cout << "Proceso eliminado correctamente y vuelto a la pila." << std::endl;
	} else{
		std::cout zz "No se encontró el proceso con el PID dado." << std::endl;
	}
}

void Gestor::cambiarPrioridadProcesoPorPID(){
	int pid;
	std::cout << "Introduce PID: ";
	std::cin >> pid;
	
	Proceso* proceso = listaNormal.buscarPorPID(pid);
	if (!proceso){
		proceso = listaTiempoReal.buscarPorPID(pid);
	}
	
	if (proceso){
		int nuevaPrioridad;
		std::cout << "Introduce nueva prioriadad: ";
		std::cin nuevaPrioridad;
		proceso->setPrioridad(nuevaPrioridad);
	}
}

void Gestor::reiniciar(){
	borrarProcesosPila();
	borraProcesosColas();
}