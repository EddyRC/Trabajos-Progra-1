//Este Programa fue hecho por: Edgar Reyes #Carnet: RC18050

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	system("color 4F");
	float precioD;
	float precioIVA; 
	float ventaF;
	int S;
	
	//Solicitamos los datos necesarios (en este caso la cantidad 
	//de sacos a comprar al usuario)
	cout << "Bienvenido a Exportaciones Wismichu" << endl;
	cout <<"Ingrese la cantidad de sacos que desea comprar: "<< endl;
	cin >>S; //Guardamos ese dato en la variable S
	
	//Ahora evaluamos si el usuario lleva 100 o mas de 100 sacos
	if (S >= 100 && S<=200) {
		precioD = S * 0.10; //Se aplica un descuento del 10%
		precioIVA = S * 0.13; //Se aplica el impuesto de IVA 
		ventaF = S * 100 + precioIVA - precioD;
		// lleva mas de 100 sacos, se le aplicara un descuento del 10% 
		cout << "Usted lleva 100 o mas de 100 sacos, El precio final de esta venta (incluyendo IVA) es de: $"<<ventaF<<endl;
	}
	
	//Evaluamos si el usuario lleva menos de 100 sacos
	else if (S < 100) {
		precioIVA = S * 0.13;
		ventaF = S * 100 + precioIVA - precioD;
		// lleva menos de 100 sacos, esta venta no tiene descuento 
		cout << "Usted lleva menos de 100 sacos, El precio final de esta venta (incluyendo IVA) es de: $"<<ventaF<<endl;
	}
	
	//evaluamos si lleva mas de 200 sacos
	else if (S > 200 && S <=250) {
		precioD = S * 0.15; //aplcamos el descuento respectivo
		precioIVA = S * 0.13; 
		ventaF = S * 100 + precioIVA - precioD;
		// lleva mas de 200 sacos, se le aplicara un descuento del 15% 
		cout << "Usted lleva 200 o mas sacos, El precio final de esta venta (incluyendo IVA) es de: $"<<ventaF<<endl;
	}
	
	//evaluamos si lleva mas de 250
	else if (S > 250 && S < 300) {
		precioD = S * 0.20;
		precioIVA = S * 0.13;
		ventaF = S * 100 + precioIVA - precioD;
		// lleva entre 250 y 300 sacos , se le aplicara un descuento del 20% 
		cout << "Usted lleva 250 o mas sacos, El precio final de esta venta (incluyendo IVA) es de: $"<<ventaF<<endl;
	}
	
	//evaluamos si lleva mas de 300 sacos
	else if (S >= 300) {
		precioD = S * 0.25;
		precioIVA = S * 0.13;
		ventaF = S * 100 + precioIVA - precioD;
		// lleva mas de 300 sacos, se le aplicara un descuento del 25% 
		cout << "Usted lleva mas de 300 sacos, El precio final de esta venta (incluyendo IVA) es de: $"<<ventaF<<endl;
	}
	
	
	return 0;
}
