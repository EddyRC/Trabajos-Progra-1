/*
Programa realizado por:
    Edgar Antonio Reyes Ceron.
# de Carnet:
   RC18050.
Ultima actualizacion:
   Sabado, 17 de noviembre de 2018.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>//para utilizar la funcion de crear archivos de texto
#include <windows.h>

using namespace std;

int main() {

	int i, j, temp, ventas;
	float p, total;
	int unidades;
	
	//para crear archivos de texto en donde se almacenaran las ventas
	ofstream fs("Ventas en orden ascendente.txt");
	ofstream fs2("Ventas en orden descendente.txt");
	
	cout<<"Cuantas ventas ha realizado ahora: ";
	cin>>ventas;
	system("cls");
	
	int vector[ventas];
	
	for (i = 1; i <= ventas; i++){
		cout<<"Ingrese el precio de la venta "<<i<<": $";
		cin>>p;
		cout<<"Ingrese la cantidad de unidades vendidas en la venta "<<i<<" : ";
		cin>>unidades;
		
		total = (unidades * p);
		vector[i] = total;
	}
	system("cls");
	
	//PARA MOSTRAR LAS VENTAS DE MANERA ASCENDENTE
	for (i = 1; i <= ventas; i++){
		for (j = i + 1; j <= ventas; j++){
			if (vector[j] < vector[i]){
				temp = vector[j];
				vector[j] = vector[i];
				vector[i] = vector[j];
				vector[i] = temp;
			}
		}
	}
	
	cout<<endl;
	cout<<"Ventas en orden Ascendente: "<<endl;
	for(i = 1; i <= ventas; i++){
		cout<<"$"<<vector[i]<<"  ";	
	}
	
	/*lo guardamos en el archivo de texto antes declarado como
	ventas en orden ascendente*/
	fs<<"Ventas en orden Ascendente: "<<endl;
	for(i=1; i<=ventas; i++){	
		fs<<vector[i]<<endl;
	}
	fs.close();
	
	//PARA MOSTRAR LAS VENTAS DE MANERA DESCENDENTE
	for (i = 1; i <= ventas; i++){
		for (j = i + 1; j <= ventas; j++){
			if (vector[j] > vector[i]){
				temp = vector[j];
				vector[j] = vector[i];
				vector[i] = vector[j];
				vector[i] = temp;
			}
		}
	}
	
	cout<<endl;
	cout<<"Ventas en orden Descendente: "<<endl;
	for(i = 1; i <= ventas; i++){
		cout<<"$"<<vector[i]<<"  ";
	}
	
	/*lo guardamos en el archivo de texto antes declarado como
	ventas en orden descendente*/
	fs2<<"Ventas en orden Descendente: "<<endl;
	for(j=1; j<=ventas; j++){	
		fs2<<vector[j]<<endl;
	}
	fs2.close();
	
	system("pause");
	return 0;
}
