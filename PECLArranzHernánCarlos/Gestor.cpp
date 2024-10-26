#include "Gestor.hpp"
#include <algorithm>
Gestor::Gestor(){
	pidCounter = 0;
	usuarioCounter = 0;
	int n = 600;
	int a = new int[n];
	for(int i = 0; i < n; ++i){
		a[i] = i + 300;
	}
	random_shuffle(a, a + n);
	arrayPIDs = a;
}
void Gestor::genera12Procesos() {
	for (int i = pidCounter; i < pidCounter+12; i++) {
        int pid = arrayPIDs[i];
		
        std::string usuario = "usuario" + std::to_string(usuarioCounter++);
        bool tiempoReal = rand() % 2;
        Proceso* proceso = new Proceso(pid, usuario, tiempoReal);
        pila.insertar(proceso);
    }
	pidCounter = pidCounter + 12;
}


void Gestor::muestraProcesos() const {
    pnodoPila actual = pila.ultimo;
    while (actual != nullptr) {
        Proceso* proceso = actual->proceso;
        std::cout << "El proceso cuyo PID es " << proceso->getPID() 
                  << " es de tipo " << (proceso->esTiempoReal() ? "en tiempo real" : "normal") << std::endl;
        actual = actual->siguiente;
    }
}


void Gestor::borraProcesosPila(){
	while (!pila.estaVacia()) {
        pila.extraer();
    }
}
void Gestor::encolarProcesos() {
    int n = pila.getLongitud(); 
	
	//Comprobar que hay procesos para encolar
	if n > 0{
		int* prioridadesNormales = new int[n]; // Para procesos normales
		int* prioridadesTiempoReal = new int[n]; // Para procesos en tiempo real

		// Generar prioridades para procesos normales (-19 a +19)
		for (int i = 0; i < n; ++i) {
			prioridadesNormales[i] = rand() % 39 - 19; // Generar números entre -19 y +19
		}
		random_shuffle(prioridadesNormales, prioridadesNormales + n); // Desordenar prioridades normales

		// Generar prioridades para procesos en tiempo real (0 a 99)
		for (int i = 0; i < n; ++i) {
			prioridadesTiempoReal[i] = rand() % 100; // Generar números entre 0 y 99
		}
		random_shuffle(prioridadesTiempoReal, prioridadesTiempoReal + n); // Desordenar prioridades en tiempo real

		int indexNormales = 0;
		int indexTiempoReal = 0; 
		
		while (!pila.estaVacia()) {
			Proceso* proceso = pila.extraer();
			proceso->setEjecucion(false); // Establecer el estado en parado

			// Asignar prioridad según el tipo de proceso
			if (proceso->esTiempoReal()) {
				proceso->setPrioridad(prioridadesTiempoReal[indexTiempoReal++]);
			} else {
				proceso->setPrioridad(120 + prioridadesNormales[indexNormales++]); // Aplicar cálculo para procesos normales
			}

			//Determinar la cola en la que tine que ir según el tipo de cola y según la longitud de cada cola
			int indiceCola = 0;
			if (proceso->esTiempoReal()) {
				indiceCola = (colas[2].getLongitud() <= colas[3].getLongitud()) ? 2 : 3; 
			} else {
				indiceCola = (colas[0].getLongitud() <= colas[1].getLongitud()) ? 0 : 1;
			}
			colas[indiceCola].insertar(proceso);
		}

		// Liberar memoria
		delete[] prioridadesNormales;
		delete[] prioridadesTiempoReal;
	}
	else{
		std::cout << "No hay procesos en pila para encolar." << std::endl;
	}
}

void Gestor::muestraProcesosGPUs0y1() const{
	std::cout << "GPU 0:" << std::endl;
	colas[0].mostrar();
	std::cout << "GPU 1:" << std::endl;
	colas[1].mostrar();
}

void Gestor::muestraProcesosGPUs2y3() const{
	std::cout << "GPU 2:" << std::endl;
	colas[2].mostrar();
	std::cout << "GPU 3:" << std::endl;
	colas[3].mostrar();
}
	std::cout << "GPU 2:" << std::endl;
	colas[2].mostrar();
	std::cout << "GPU 3:" << std::endl;
	colas[3].mostrar();
}
void Gestor::borraProcesosColas() {
    for (int i = 0; i < 4; i++) {
        while (!colas[i].estaVacia()) {
            colas[i].eliminar();
        }
    }
}

void Gestor::enlistarProcesos() {
    for (int i = 0; i < 4; i++) {
        while (!colas[i].estaVacia()) {
            Proceso* proceso = colas[i].desencolar();
            proceso->setEjecucion(true);
            if (i < 2) {
                listaNormal.insertar(proceso);
            } else {
                listaTiempoReal.insertar(proceso);
            }
        }
    }
}

void Gestor::muestraProcesosNormal() const {
    std::cout << "Lista Normal:" << std::endl;
    listaNormal.mostrar();
}

void Gestor::muestraProcesosTiempoReal() const {
    std::cout << "Lista Tiempo Real:" << std::endl;
    listaTiempoReal.mostrar();
}

void Gestor::buscarProcesos() const {
    Proceso* menorPrioridadNormal = nullptr;
    Proceso* mayorPrioridadTiempoReal = nullptr;

    // Buscar proceso normal de menor prioridad
    NodoLista* actual = listaNormal.cabeza;
    while (actual != nullptr) {
        if (menorPrioridadNormal == nullptr || actual->proceso->getPrioridad() < menorPrioridadNormal->getPrioridad()) {
            menorPrioridadNormal = actual->proceso;
        }
        actual = actual->siguiente;
    }

    // Buscar proceso en tiempo real de mayor prioridad
    actual = listaTiempoReal.cabeza;
    while (actual != nullptr) {
        if (mayorPrioridadTiempoReal == nullptr || actual->proceso->getPrioridad() > mayorPrioridadTiempoReal->getPrioridad()) {
            mayorPrioridadTiempoReal = actual->proceso;
        }
        actual = actual->siguiente;
    }

    std::cout << "Proceso Normal de menor prioridad:" << std::endl;
    if (menorPrioridadNormal != nullptr) {
        menorPrioridadNormal->mostrar();
    } else {
        std::cout << "No hay procesos normales en la lista." << std::endl;
    }

    std::cout << "Proceso en Tiempo Real de mayor prioridad:" << std::endl;
    if (mayorPrioridadTiempoReal != nullptr) {
        mayorPrioridadTiempoReal->mostrar();
    } else {
        std::cout << "No hay procesos en tiempo real en la lista." << std::endl;
    }
}

void Gestor::buscarProcesoPorNombreUsuario() const {
    std::string nombreUsuario;
    std::cout << "Ingrese el nombre de usuario: ";
    std::cin >> nombreUsuario;

    bool encontrado = false;

    // Buscar en la lista normal
    NodoLista* actual = listaNormal.cabeza;
    while (actual != nullptr) {
        if (actual->proceso->getUsuario() == nombreUsuario) {
            actual->proceso->mostrar();
            encontrado = true;
        }
        actual = actual->siguiente;
    }

    // Buscar en la lista de tiempo real
    actual = listaTiempoReal.cabeza;
    while (actual != nullptr) {
        if (actual->proceso->getUsuario() == nombreUsuario) {
            actual->proceso->mostrar();
            encontrado = true;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        std::cout << "No se encontraron procesos para el usuario: " << nombreUsuario << std::endl;
    }
}


void Gestor::eliminarProcesoPorPID() {
    int pid;
    std::cout << "Ingrese el PID del proceso a eliminar: ";
    std::cin >> pid;

    Proceso* proceso = listaNormal.buscarPorPID(pid);
    if (proceso == nullptr) {
        proceso = listaTiempoReal.buscarPorPID(pid);
    }

    if (proceso != nullptr) {
		std::cout << "PID\tUSUARIO\tESTADO\tPRIORIDAD\tTIPO" << std::endl;
        std::cout << proceso->getPID() << "\t" 
                  << proceso->getUsuario() << "\t" 
                  << (proceso->mostrar_proceso() ? "Ejecución" : "Parado") << "\t" 
                  << proceso->getPrioridad() << "\t\t" 
                  << (proceso->esTiempoReal() ? "Tiempo Real" : "Normal") << std::endl;
        std::cout << "El proceso cuyo PID es " << proceso->getPID()
                  << " es de tipo " << (proceso->esTiempoReal() ? "en tiempo real" : "normal")
                  << ", su estado es " << (proceso->mostrar_proceso() ? "ejecución" : "parado")
                  << " y su prioridad es: " << proceso->getPrioridad() << std::endl;

        listaNormal.eliminarPorPID(pid);
        listaTiempoReal.eliminarPorPID(pid);
    } else {
        std::cout << "No se encontró un proceso con el PID " << pid << std::endl;
    }
}

void Gestor::cambiarPrioridadProcesoPorPID() {
    int pid, nuevaPrioridad;
    std::cout << "Ingrese el PID del proceso al que desea cambiar la prioridad: ";
    std::cin >> pid;

    Proceso* proceso = listaNormal.buscarPorPID(pid);
    if (proceso == nullptr) {
        proceso = listaTiempoReal.buscarPorPID(pid);
    }

    if (proceso != nullptr) {
        // Mostrar datos del proceso antes de cambiar la prioridad
        std::cout << "PID\tUSUARIO\tESTADO\tPRIORIDAD\tTIPO" << std::endl;
        std::cout << proceso->getPID() << "\t" 
                  << proceso->getUsuario() << "\t" 
                  << (proceso->mostrar_proceso() ? "Ejecución" : "Parado") << "\t" 
                  << proceso->getPrioridad() << "\t\t" 
                  << (proceso->esTiempoReal() ? "Tiempo Real" : "Normal") << std::endl;

        std::cout << "Ingrese la nueva prioridad para el proceso: ";
        std::cin >> nuevaPrioridad;

        // Cambiar la prioridad del proceso
        proceso->setPrioridad(nuevaPrioridad);

        // Mostrar datos del proceso después de cambiar la prioridad
        std::cout << "PID\tUSUARIO\tESTADO\tPRIORIDAD\tTIPO" << std::endl;
        std::cout << proceso->getPID() << "\t" 
                  << proceso->getUsuario() << "\t" 
                  << (proceso->mostrar_proceso() ? "Ejecución" : "Parado") << "\t" 
                  << proceso->getPrioridad() << "\t\t" 
                  << (proceso->esTiempoReal() ? "Tiempo Real" : "Normal") << std::endl;
    } else {
        std::cout << "No se encontró un proceso con el PID " << pid << std::endl;
    }
}


void Gestor::reiniciar() {
    borraProcesosPila();
    borraProcesosColas();
    listaNormal.~Lista();
    listaTiempoReal.~Lista();
}

// Métodos adicionales para adaptarse al main
int Gestor::ProcesosEnPila() const {
    return pila.getLongitud();
}

int Gestor::ProcesosEnGPU0() const {
    return colas[0].getLongitud();
}

int Gestor::ProcesosEnGPU1() const {
    return colas[1].getLongitud();
}

int Gestor::ProcesosEnGPU2() const {
    return colas[2].getLongitud();
}

int Gestor::ProcesosEnGPU3() const {
    return colas[3].getLongitud();
}

int Gestor::ProcesosEnListaNormal() const {
    return listaNormal.getLongitud();
}

int Gestor::ProcesosEnListaTiempoReal() const {
    return listaTiempoReal.getLongitud();
}

int Gestor::ProcesosEnArbol() const {
    // Implementar si se añade la funcionalidad del árbol
    return 0;
}