//Este programa fue hecho por: Edgar Antonio Reyes Ceron.
//#Carnet: RC18050
#include <iostream>//para trabajar con cout y cin
#include <windows.h>//para permitir el system("pause")

using namespace std;

int peticion(){ //creamos un funcion que nos retornara un dato y ese sera la seleccion del usuario

	int opcion;//inicializamos una variable que a continuacion haremos uso de ella
			
	cout <<"--------------------------"<<endl;
	cout <<"      Buenos dias!    "<<endl;
	cout <<" Bienvenido al sistema de \n  calculo de insumos."<<endl;    //este es un saludo
	cout <<"--------------------------"<<endl;
	system ("pause"); 
	system ("cls");  //limpiamos pantalla
	cout <<"---En que podemos ayudarle--- \n      el dia de hoy?"<<endl;
	cout <<"-----------------------------"<<endl;
	cout <<"Ingrese una opcion [1-2]:"<<endl; 	//aqui se solicitan los datos al usuario
	cout <<"\n 1- Calcular requerimientos \n  para la produccion de soda."<<endl;
	cout <<"\n 2- Calcular requerimientos \n  para la produccion de jugo."<<endl;
	cin >>opcion;//guardamos la seleccion del usuario en la variable
	
	return opcion;//retornamos ese dato guardado en la variable opcion
}

int  validacion(){/*Creamos una funcion de validacion, la cual nos servira para que el usuario no intruduzca
caracteres, o un numero menor o igual a cero*/
	int insumo;
	while (cin.fail() || insumo<=0) {
 		system ("cls");
		cin.clear();
		cin.ignore(1024 , '\n');
		cout <<"Los datos que introdujo son incorrectos, vuelva a intentarlo: "<<endl;
		cin >>insumo;/*se guarda el nuevo dato solicitado y se evaluara de nuevo para verificar 
		si concuerda con los parametros que establecemos*/	
	}
	return insumo;//retornamos el dato que resulta de la validacion
}
int main() {
	
	system ("color 5B"); /*En esta linea de codigo le damos color a la fuente en la consola y tambien 
	le cambiamos color al fondo de la consola*/
	 
	int soda;
	int jugo;			
	int agua;			//inicializacion de variables
	int azucar;
	int op;
	int valid;
	
	op = peticion();//llamamos a la funcion para pedir los datos al usuario
	
	/*Realizamos una validacion para evitar que existan problemas si se introduce texto
	o un numero que no se encuentra en el rango que hemos establecido [1-2]*/
	while (cin.fail() || op<=0 || op>=3 ) {
		system ("cls");//esto es para borrar la pantalla cada vez que ejecute la validacion
		cin.clear();
		cin.ignore(1024 , '\n');
		cout <<"Opcion incorrecta, vuelva a intentarlo: "<<endl;
		cout <<"Ingrese una opcion [1-2]:"<<endl;
		cout <<"\n 1- Calcular requerimientos \n  para la produccion de soda."<<endl;
		cout <<"\n 2- Calcular requerimientos \n  para la produccion de jugo."<<endl;
		cin >>op;//se guarda el nuevo dato solicitado y se evaluara de nuevo	
	}
	system ("cls");/*hacemos un system cls para limpiar de la pantalla lo anterior 
	y proseguimos a evaluar la opcion que el usuario ha seleccionado con un switch*/
	
	switch (op){//lo que se evaluara en switch es el dato que el usuario proporciona
		/*en este primer caso hacemos el calculo para los insumos requeridos en la 
		fabricacion de la soda*/
		case 1: cout <<"Introduzca la cantidad de\nsodas que se van a producir:"<<endl;//solicitamos la cantidad
				cin >>soda;//guardamos ese dato en l variable respectiva
				
				valid = validacion();//llamamos la funcion validacion para corregir errores
				
				agua = valid*500;//calculamos la cantidad requerida de agua
				azucar = valid*800;//calculamos la cantidad requerida de azucar
				
				system ("cls");//limpiamos la pantalla
				
				//Mostramos al usuario los ya calculados requerimientos
				cout <<"Para esta produccion se necesitaran "<<agua<<" ml de agua \n y "<<azucar<<" gr de azucar."<<endl;
				break;
				
		/*en este segundo caso hacemos el calculo para los insumos requeridos en la 
		fabricacion del jugo*/		
		case 2: cout <<"Introduzca la cantidad de\njugos que se van a producir:"<<endl;//solicitamos la cantidad
				cin >>jugo;//guardamos ese dato en esta variable
				
				valid = validacion();//llamamos la funcion validacion para corregir errores
				
				agua = valid*600;//calculamos la cantidad requerida de agua
				azucar = valid*700;//calculamos la cantidad requerida de azucar
				
				system ("cls");//limpiamos la pantalla
				
				//Mostramos al usuario los ya calculados requerimientos
				cout <<"Para esta produccion se necesitaran "<<agua<<" ml de agua \n y "<<azucar<<" gr de azucar."<<endl;
				break;
	}
	
	return 0;
}
