#include <iostream>

using namespace std;
const int minimo = 0, maximo = 10;

int main(int argc, char** argv)
{
	int n;
    cout << "Introduzca un numero entre " << minimo << " y " << maximo << "." << endl;
    cin >> n;
	if ((n < minimo) || (n > maximo))
		cout << "El valor " << n << " esta fuera del rango." << endl;
	else
		switch(n) {
	    case 0:
			cout << "No existe defininicion de primo en este caso" << endl;
			break;
		case
				
		}

	
	return 0;
}