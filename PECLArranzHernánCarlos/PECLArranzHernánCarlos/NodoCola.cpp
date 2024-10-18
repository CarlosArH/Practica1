#include "NodoCola.hpp"

NodoCola::NodoCola(Proceso* p, NodoCola* sig)
{
	Proceso* proceso = p;
	siguiente = sig;
}
NodoCola::~NodoCola()
{
}