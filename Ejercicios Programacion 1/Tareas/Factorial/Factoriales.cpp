//Este programa fue hecho por Edgar Reyes
//Carnet: RC18050
#include <iostream>//libreria para trabajar con datos de entrada y salida de los mismos(cin,cout)

using namespace std;

int main() {
	system ("color 6B"); /*le añadimos color a las letras 
	mostradas en consola y al fondo de la consola*/
	
	int numero; /*inicializamos la variable numero en tipo entero (aqui es donde 
	se guardara el dato que el usuario ingrese*/
	int factorial = 1; /*Inicializamos la variable factorial en entero*/
	
	/*hacemos una pequeña validacion, que el 
	usuario no introduzca un numero menor o igual a cero*/
	do {
	system ("cls");
	cout<<"       -------------------     "<<endl;
	cout<<"    -------------------------  "<<endl;
	cout<<"---------------------------------"<<endl; 
	cout <<"Ingrese un numero:";//Pedimos el numero al usuario
	cin >>numero; //lo guardamos en la variable numero
	}while (numero<=0); //Y pasara a evaluar la condicion
	
	/*para poder calcular el 
	factorial haremos uso de un ciclo for*/
	for (int i=1; i<=numero; i++){ 
	
	factorial = factorial*i;
	}
	
	//mostramos el resultado en pantalla
	cout<<"El factorial de su numero es: "<<factorial<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"    -------------------------  "<<endl;
	cout<<"       -------------------     "<<endl; 
	return 0;
}	

