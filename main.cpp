/*Este programa fue hecho por: Edgar Antonio Reyes Ceron
#Carnet: RC18050 */

#include <iostream> // para trabajar con las entradas y salidas (cout, cin)
#include <iomanip> //para dar presicion con el metodo setpresicion a un flotante
#include <windows.h> //libreria para reproducir el sonido en consola (vease en la linea #68 y #73)

using namespace std;

int main() {
	
	system ("color 6B"); /*En esta linea de codigo le damos color a la fuente en la consola y tambien 
	le cambiamos color al fondo de la consola*/
	
	/*Inicializamos las variables venta y sueldo en double debido a la posibilidad
	de que el usuario tenga una venta en decimales y en 
	tipo entero */ 
	double venta;  
	double sueldo;
	
	//Solicitamos la venta al usuario
	cout << "Ingrese lo que ha vendido el vendedor: " << endl;
	cin >>venta;
	
	/*Ahora validamos si el usuario ha introducido un dato menor o igual que cero
	y que tampoco sea texto*/
	while ( cin.fail() || venta <=0 ) {
		cin.clear();
		cin.ignore(1024 , '\n');
		/*Volvemos a pedir el dato a el usuario, guardando 
		nuevamente en la variable venta el nuevo dato que 
		introdujo, si este es incorrecto el sistema lo volvera a solicitar
		y volvera a este paso, hasta que el dato sea correcto continuara 
		con lo demas del programa*/
		cout << "El valor que usted ha ingresado es incorrecto. \nIngrese lo que ha vendido el vendedor: " << endl;
		cin >>venta;
	}
	
	//Ahora verificamos si el vendedor ha tenido una venta entre 0 y 500,000
	if ( venta >= 0 && venta <= 500000){
		sueldo = 80000;
	}
	
	//Ahora verificamos si el vendedor ha tenido una venta entre 500,001 y 1,000,000
	else if ( venta >= 500001 && venta <= 1000000){
		sueldo = 160000;
	}
	
	//Ahora verificamos si el vendedor ha tenido una venta entre 1,000,001 y 1,500,000
	else if ( venta >= 1000001 && venta <= 1500000){
		sueldo = 320000;
	}	
	
	//Ahora verificamos si el vendedor ha tenido una venta entre 1,500,001 y 2,500,000
	else if ( venta >= 1500001 && venta <= 2500000){
		sueldo = 450000;
	}	
	
	//Ahora verificamos si el vendedor ha tenido una venta entre 2,500,001 y 4,000,000
	else if ( venta >= 2500001 && venta <= 4000000){
		sueldo = 550000;
	}
	
	//Ahora verificamos si el vendedor ha tenido una venta de mas de 4,000,000
	else if ( venta > 4000000) {
		sueldo = venta * 0.20;
	}
	
	char soundfile[] = "nexus.wav"; //Ruta al fichero de audio
		
	//Imprimimos en pantalla el sueldo acorde a la venta que ha realizado
	cout << "Su sueldo es de: $" << fixed << setprecision(2) << sueldo << endl;	
	
	PlaySound ((LPCSTR)soundfile, NULL, SND_FILENAME); //En esta linea se solicita al compilador que reproduzca el sonido
	
	return 0;
}
