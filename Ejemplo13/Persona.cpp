#include "Persona.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace stc;

Persona::Persona(int edad){
	this->edad = edad;
	this->genero = rand() % 2;
	generarDni();
}
Persona::~Persona(){}

void Persona::generarDni(){
	static const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 8; ++i){
		dni[i] = '0' + rand() % 10;
	}
	dni[8] = letras[rand() %26];
	dni[9] = '\0';
}

int Person::getEdad(){
	return edad;
}

bool Persona::esMujer(){
	
}

bool Persona::setEdad(int edad){
	this->edad = edad;
}

void Persona::mostrar(){
	cout <<"DNI: " << dni << "\n";
	cout << "Género: " << (genero ? "Mujer" : "Hombre") << "\n";
	cout << "Edad: " << edad << "\n";
	cout << "------------------------\n";
}