#include "NodoPila.hpp"
using namespace std;

NodoPila::NodoPila(Proceso* p, NodoPila* sig)
{
	proceso = p;
	siguiente = sig;
}

NodoPila::~NodoPila(){
}