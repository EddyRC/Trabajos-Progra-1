/*Este programa fue hecho por:
Edgar Antonio Reyes Ceron.
Carnet: RC18050.*/

#include <iostream>//para trabajar con datos de entrada y salida (cout y cin)
#include <windows.h>//para usar el comando system(cls)
#include <iomanip> //para dar presicion con el metodo setpresicion a un flotante

using namespace std;

int peticion(){/*creamos una funcion que solicite los datos al usuario y 
posterior a ello, lo almacene en una variable que usaremos despues*/
	int min;
	cout << "Cuantos minutos ha hablado: " <<endl;
	cin >> min;
	return min;//nuestro dato de retorno sera lo que el usuario ha digitado
}
int validacion(){/*Creamos una funcion de validacion, la cual nos servira para que el usuario no intruduzca
caracteres, o un numero menor o igual a cero*/
	int mins;
	while (cin.fail() || mins<=0) {
 		system ("cls");
		cin.clear();
		cin.ignore(1024 , '\n');
		cout <<"Opcion incorrecta, vuelva a intentarlo: "<<endl;
		cout << "Cuantos minutos ha hablado: " <<endl;
		cin >>mins;/*se guarda el nuevo dato solicitado y se evaluara de nuevo para verificar 
		si concuerda con los parametros que establecemos*/	
	}
	return mins;//retornamos el dato que resulta de la validacion
}

int main() {
	system ("color 6F"); /*le añadimos color a las letras 
	mostradas en consola y al fondo de la consola*/
	
	float pago = 1;
	int minu = 0;
	int valid;
	cout <<"   ~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout <<"Bienvenido al servicio de pago \n  por llamada de Vodafone"<<endl;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout <<"   ~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	system ("pause");//para detener el mensaje hasta que el usuario decida proseguir
	system ("cls");//limpiamos pantalla
	
	minu = peticion();//llamamos la funcion peticion para pedir los datos en pantalla
	valid = validacion ();//llamamos la funcion validacion para corregir errores
 	
	system ("cls");//limpiamos pantalla
	
	//evaluamos si el usuario ha hablado entre 1 y 10 minutos
	if (valid>=1 && valid<=10){
		pago = valid;
		//mostramos en pantalla el pago de acuerdo al tiempo de llamada
		cout <<"Su pago en relacion al tiempo que ha hablado es de: $"<<fixed<<setprecision(2)<<pago*0.05<<endl;
	}
	//evaluamos si el usuario ha hablado entre 11 y 15 minutos
	else if (valid>=11 && valid<=15){
		pago = valid;
		//mostramos en pantalla el pago de acuerdo al tiempo de llamada
		cout <<"Su pago en relacion al tiempo que ha hablado es de: $"<<fixed<<setprecision(2)<<pago*0.08<<endl;
	}
	//evaluamos si el usuario ha hablado mas de 15 minutos
	else if (valid>=16){
		pago = valid;
		//mostramos en pantalla el pago de acuerdo al tiempo de llamada
		cout <<"Su pago en relacion al tiempo que ha hablado es de: $"<<fixed<<setprecision(2)<<pago*0.10<<endl;
	}
	return 0;
}

