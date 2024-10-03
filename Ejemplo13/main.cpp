#include "Persona.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

usingf namespace std;

bool edadRepetida(int edad, int edades[], int size){
	for(int i = 0; i < size; ++i){
		if (edades[i] == edaad){
			return true;
		}
	}
	return false;
}
int main(int argc, char**argv){
	srand(time(0));
	
	Persona* personas[10];
	int edades[10] = (0);
	
	for (int i = 0; i < 10; ++i){
		int edad;
		do{
			edad = rand() % 10 +18;
		} while (edadRepetida(edad, edades, i));
		
		edades[i] = edad;
		personas[i] = new Persona(edad);
	}
	
	for (int i = 0; i < 10; i++){
		personas[i]->mostrar();
		delete personas[i];	
	}
	
	return 0;
}