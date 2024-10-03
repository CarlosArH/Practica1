#include "NodoPila.hpp"
using namespace std;

NodoPila::NodoPila(int v, NodoPila* sig)
{
	valor = v;
	siguiente = sig;
}

NodoPila::~NodoPila(){
}