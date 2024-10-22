#include "NodoPila.hpp"
using namespace std;

NodoPila::NodoPila(Proceso* p, NodoPila* sig)
{
	Proceso* proceso = p;
	siguiente = sig;
}

NodoPila::~NodoPila(){
}