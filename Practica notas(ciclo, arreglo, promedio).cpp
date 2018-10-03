//Este programa fue hecho por: Edgar Antonio Reyes Ceron 
//Carnet: RC18050

#include <cstdlib> //para limpiar la pantalla
#include <iostream> // para trabajar con datos de entrada y salida cout y cin

using namespace std;

int main() {
	
	float notas [5];
	float sumar = 0;
	
	for (int i=0; i<=4 ; i++) { //ciclo para pedir las notas
			do { //el do es parte de la validacion
				system("cls"); //limpia la pantalla
				cout << "Ingrese nota " <<i+1<<":"<< endl; //solicitamos al usuario la nota
				cin >> notas [i]; //guardamos en el arreglo
			} while (notas[i]<0 || notas[i]>11); //validacion 
		sumar = sumar + notas [i]; //acumulador
	}
	
	system("cls"); //limpia la pantalla
	
	for (int i=0; i<=4; i++){
		cout <<"Notita "<<i+1<<":"<<notas[i]<<endl;
	}
	
	cout << "El promedio de notas es de: " << sumar/5 << endl;
	return 0;
}
