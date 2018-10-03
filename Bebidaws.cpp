//Este programa fue hecho por: Edgar Antonio Reyes Ceron.
//#Carnet: RC18050
#include <iostream>//para trabajar con cout y cin
#include <windows.h>//para permitir el system("pause")

using namespace std;

int peticion(){
	int opcion;
			
	cout <<"--------------------------"<<endl;
	cout <<"      Buenos dias!    "<<endl;
	cout <<" Bienvenido al sistema de \n  calculo de insumos."<<endl;
	cout <<"--------------------------"<<endl;
	system ("pause");
	system ("cls");
	cout <<"---En que podemos ayudarle--- \n      el dia de hoy?"<<endl;
	cout <<"-----------------------------"<<endl;
	cout <<"Ingrese una opcion [1-2]:"<<endl;
	cout <<"\n 1- Calcular requerimientos \n  para la produccion de soda."<<endl;
	cout <<"\n 2- Calcular requerimientos \n  para la produccion de jugo."<<endl;
	cin >>opcion;
	
	return opcion;
}

int main() {
	
	system ("color 5B"); /*En esta linea de codigo le damos color a la fuente en la consola y tambien 
	le cambiamos color al fondo de la consola*/
	 
	int soda;
	int jugo;			
	int agua;			//inicializacion de variables
	int azucar;
	int op;
	
	
	op = peticion();
	
	while (cin.fail() || op<=0 || op>=3 ) {
		system ("cls");
		cin.clear();
		cin.ignore(1024 , '\n');
		cout <<"Opcion incorrecta, vuelva a intentarlo: "<<endl;
		cout <<"Ingrese una opcion [1-2]:"<<endl;
		cout <<"\n 1- Calcular requerimientos \n  para la produccion de soda."<<endl;
		cout <<"\n 2- Calcular requerimientos \n  para la produccion de jugo."<<endl;
		cin >>op;	
	}
	system ("cls");
	switch (op){
		case 1: cout <<"Introduzca la cantidad de\nsodas que se van a producir:"<<endl;
				cin >>soda;
				agua = soda*500;
				azucar = soda*800;
				system ("cls");
				cout <<"Para esta produccion se necesitaran "<<agua<<" ml de agua \n y "<<azucar<<" gr de azucar."<<endl;
				break;
		case 2: cout <<"Introduzca la cantidad de\njugos que se van a producir:"<<endl;
				cin >>jugo;
				agua = jugo*600;
				azucar = jugo*700;
				system ("cls");
				cout <<"Para esta produccion se necesitaran "<<agua<<" ml de agua \n y "<<azucar<<" gr de azucar."<<endl;
				break;
	}
		
	
	
	return 0;
}
