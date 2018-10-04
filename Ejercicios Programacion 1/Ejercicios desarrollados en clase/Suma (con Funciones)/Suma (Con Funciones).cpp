//Este programa fue hecho por Edgar Reyes
//Carnet: RC18050

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

void l();//declaracio de funcion /no retorna nada / no recibe parametros'
int sumar(int a, int aux); //declaracion de la funcion suma
int pedirNumSumar ();

int main() {
	system ("color 5F");
	int n = 1; //servira para llevar el numero de ciclos realizados (contador)
	int suma = 0;//(acumulador) porque va en cada ciclo acumulando iteraciones en cada uno de los ciclos
	int aux;//son variables para realizar una operacion de intercambio de valores (son temporales)
	int vn;//variable normal su valor cambia de dos a 4
	
	vn = pedirNumSumar ();
	
	while(n <= vn){ //vn sera la cantidad de numeros que el quiere sumar
		l (); //llamamos a la funcion
		
		cout << "Ingrese el numero " <<n<<endl; /*n va concatenada porque 
		la usaremos como variable auxiliar*/
		cin >> aux; //guardamos en la variable aux
		//suma = suma + aux; //hacemos la suma de los numeros en cada iteracion
		suma = sumar (suma, aux);// ahora con la funcion solo la llamamos
		n++; //incrementa en una unidad despues de cada iteracion
	}
	l (); //llamamos a la funcion
	
	cout << "La suma de sus numeros es: "<<suma<<endl;
	system ("pause");
	l ();
	cout <<"Desarrollado por: Edgar Reyes."<<endl;
	cout <<"UNIVERSIDAD DE EL SALVADOR."<<endl;
	cout <<"Version: "<<sumar (1,2)<<endl;
	
	return 0;
}
//implementacion de la funcion l (limpiar)
void l () {
	system ("cls");
	cout <<"-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-"<<endl;
	cout <<"-------------------------------"<<endl;
}
//implementacion de la funcion sumar (sumar los numeros)
int sumar (int a, int aux){
	return a+aux;
}
int pedirNumSumar (){
	int x;
	do {
	
	l (); //llamamos  la funcion

	cout << "Cuantos numeros quiere sumar [2-4]: " <<endl;
	cin >> x; //guardamos en la variable vn
	
	} while (x < 2 || x > 4);
	
	return x;
}
