#include "Cola.hpp"

Cola::Cola()
{
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

void Cola::insertar(Proceso* p) {
    pnodoCola nuevo = new NodoCola(p, nullptr);
    
    // Si la cola está vacía, simplemente inserta el nuevo nodo
    if (!primero) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        pnodoCola actual = primero;
        pnodoCola anterior = nullptr;

        // Buscar la posición correcta para insertar el nuevo nodo
        while (actual != nullptr && actual->proceso->getPrioridad() <= p->getPrioridad()) {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Si se inserta al principio
        if (anterior == nullptr) {
            nuevo->siguiente = primero;
            primero = nuevo;
        } else {
            // Inserta en medio o al final
            nuevo->siguiente = actual;
            anterior->siguiente = nuevo;
            if (actual == nullptr) {
                ultimo = nuevo; // Actualiza el último si se inserta al final
            }
        }
    }
    longitud++;
}

void Cola::mostrar() const {
    pnodoCola aux = primero;
    cout << "\tEl contenido de la cola es: " << endl;
    while (aux) {
        Proceso* proceso = aux->proceso; // Obtener el proceso del nodo
        cout << "El proceso cuyo PID es " << proceso->getPID() 
             << " es de tipo " << (proceso->esTiempoReal() ? "en tiempo real" : "normal") 
             << ", su estado es " << (proceso->mostrar_proceso() ? "ejecución" : "parado") 
             << " y su prioridad es: " << proceso->getPrioridad() << endl;
        aux = aux->siguiente; // Avanzar al siguiente nodo
    }
}

Proceso* Cola::eliminar()
{
	if (!primero) return nullptr;
    pnodoCola nodo = primero;
    Proceso* p = nodo->proceso;
    primero = nodo->siguiente;
    if (!primero) {
        ultimo = nullptr;
    }
    delete nodo;
    longitud--;
    return p;
}

Proceso* Cola ::verPrimero() const{
	return primero->proceso;
}

bool Cola::estaVacia() const {
    return primero == nullptr;
}

int Cola::getLongitud() const {
    return longitud;
}

Cola::~Cola()
{
	while(primero)
		eliminar();
}