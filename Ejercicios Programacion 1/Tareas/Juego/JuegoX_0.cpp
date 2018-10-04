/*
Programa realizado por:
    Edgar Antonio Reyes Ceron.
# de Carnet:
   RC18050.
Ultima actualizacion:
   Domingo, 30 de septiembre de 2018.
*/

#include <iostream>// para trabajar con cin y cout
#include <windows.h>//para el system ("cls")

using namespace std;

void Imprimir();//declaracion de funcion

/*esta funcion la cree con el fin de posicionar en 
la pantalla de la consola los resultados que imprime el codigo
Fuente: https://www.youtube.com/watch?v=evmIH4nyTgE */ 
void gotoxy (int x, int y){ 
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

/*esta es la funcion en la que trabaje el codigo
destinado principalmente a la funcionalidad del juego, tambien me
base en base a un codigo, hice unas mejoras añadi algunas validaciones y 
trate de respetar en la mayor medida posible la guia de estilo de Stanfford
Fuente del codigo: https://www.youtube.com/watch?v=NlKVzPpA6Rc*/
void tablero(){
	
	//Inicializo la matriz en char porque la llenaremos con caracteres
	char matriz [3][3], pj;
	/*Inicializo algunas variables en entero que usare principalmente para 
	pedir datos y hacer comparaciones*/
	int num, fila, columna;
	
	/*Realizo un ciclo que recorra toda la matriz,
	y la lleno por el momento, de espacios en blanco*/
	for (int i = 0; i<=2; i++)
	{
		for (int j = 0; j<=2; j++)
		{
			matriz [i][j] = ' ';
		}
	}
	
	/*Imprimimos una tabla guia en pantalla (para ayudar al usuario a ubicar su ficha, 
	haciendo uso de la funcion que creamos anteriormente (gotoxy) posicionamos 
	en la consola el lugar en donde deseemos que este dicha tabla, en este caso
	la deje mas o menos a una altura superior en el lado izquierdo*/
	gotoxy(2,2);cout <<" 1  |  2  |  3 ";
	gotoxy(2,3);cout <<"---------------";
	gotoxy(2,4);cout <<" 4  |  5  |  6 ";
	gotoxy(2,5);cout <<"---------------";
	gotoxy(2,6);cout <<" 7  |  8  |  9 ";
	gotoxy(20,2);cout <<"Elija la ficha con la que quieres jugar (x - o):";
	
	/*Guardamos el dato que el usuario introdujo.*/
	cin >> pj;
	system ("cls");
	
	//evaluamos si introdujo un dato correcto
	while (cin.fail() || (pj != 'x' && pj != 'o')) {
		system("cls");
		cin.clear();
		cin.ignore(999, '\n');
		Imprimir();
		gotoxy(20,4);cout <<"Opcion incorrecta, vuelva a intentarlo.";
		gotoxy(20,5);cout <<"Elija la ficha con la que quieres jugar (x - o):";
		cin >>pj;//se guarda el nuevo dato solicitado y se evaluara de nuevo	
	}
	system("cls");
	Imprimir();
	
	/*Solicito al usuario la posicion en donde este desee poner su ficha.
	Esto se hara hasta que un resulte un ganador*/
	gotoxy(20,4);cout <<"Ingrese un numero del 1 al 9: ";
	//Guardo ese dato en la variable num
	cin >> num;
	
	system("cls");

	while (cin.fail() || num <= 0 || num >= 10){
	system ("cls");
	cin.clear();
	cin.ignore(999, '\n');
	Imprimir();
	gotoxy(20,4);cout <<"Opcion incorrecta, vuelva a intentarlo: ";
	gotoxy(20,5);cout <<"Ingrese un numero del 1 al 9: ";
	cin >>num;//se guarda el nuevo dato solicitado y se evaluara de nuevo	
	}
	
	system ("cls");//limpiamos la pantalla

	Imprimir();//Invoco la funcion de la tabla guia que hicimos anteriormente
	
	//ahora hacemos esto para llenar la matriz,  conforme a las posiciones que el usuario escoja
	do {
		/*Para este caso haremos una comparacion del dato introducido y conforme a ello
		le asignaremos el dato que el usuario introdujo en la condicion que se cumpla
		a continuacion (Ejemplo: si el usuario digito el numero 3, esa sera la 
		posicion de su ficha en la matriz*/
		
		//para las filas
		if (num == 1 || num == 2 || num == 3){
			fila = 0;
		}
		else if (num == 4 || num == 5 || num == 6){
			fila = 1;
		}
		else if (num == 7 || num == 8 || num == 9){
			fila = 2;
		}
			
		//para las columnas
		if (num == 1 || num == 4 || num == 7){
			columna = 0;
		}	
		else if (num == 2 || num == 5 || num == 8){
			columna = 1;
		}
		else if (num == 3 || num == 6 || num == 9){
			columna = 2;
		}
			 
		/*Si bien recordamos, llenamos la matriz de espacios en blanco, ahora, como se 
		supone que se han llenado algunos espacios con fichas, para evitar que el usuario 
		introduzca datos en el mismo lugar, hacemos la siguiente condicion en la 
		que si la matriz ya no tiene el espacio en blanco, ya no se pueden introducir 
		fichas en ese espacio*/
			
		if (matriz[fila][columna] != ' '){
			gotoxy(1,9);cout <<"Ya esta ocupado ese puesto, ingresa otro numero";
			Imprimir();	
			if (pj == 'x'){
				pj = 'o';
			}
			else {
				pj = 'x';
			}
		}
		
		else{
			matriz[fila][columna] = pj;
			gotoxy(1,9);cout <<"                                                ";
		}
		//mostramos en pantalla el tablero de juego
		gotoxy(20,14);cout <<" "<<matriz[0][0]<<"  |  "<<matriz[0][1]<<"  |  "<<matriz[0][2];
		gotoxy(20,15);cout <<"---------------";
		gotoxy(20,16);cout <<" "<<matriz[1][0]<<"  |  "<<matriz[1][1]<<"  |  "<<matriz[1][2];
		gotoxy(20,17);cout <<"---------------";
		gotoxy(20,18);cout <<" "<<matriz[2][0]<<"  |  "<<matriz[2][1]<<"  |  "<<matriz[2][2];
		
		//Ahora verificamos filas y columnas para ver si ha ganada
		//Para ver si el usuario ha ganado en las filas
		if (matriz[0][0] == pj && matriz[0][1] == pj && matriz[0][2] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		else if (matriz[1][0] == pj && matriz[1][1] == pj && matriz[1][2] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		else if (matriz[2][0] == pj && matriz[2][1] == pj && matriz[2][2] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		
		//para ver si el usuario ha ganado en las columnas
		else if (matriz[0][0] == pj && matriz[1][0] == pj && matriz[2][0] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		else if (matriz[0][1] == pj && matriz[1][1] == pj && matriz[2][1] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		else if (matriz[0][2] == pj && matriz[1][2] == pj && matriz[2][2] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		
		//para ver si ha ganado en diagonal
		else if (matriz[0][0] == pj && matriz[1][1] == pj && matriz[2][2] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		else if (matriz[0][2] == pj && matriz[1][1] == pj && matriz[2][0] == pj){
			gotoxy(15,22);cout <<".....Gana la ficha...."<<pj;
			num = 0;
		}
		
		/*luego en este apartado, se volvera a pedir un nuevo dato por si aun no se presentan ganadores, pediremos la posicion 
		y reasignaremos eso al puesto que el usuario solicito*/
		else {
			gotoxy(20,2);cout <<" Ingrese del 1 - 9: ";
			cin >> num;
			system("cls");
			while (cin.fail() || num <= 0 || num >= 10) {
			system ("cls");
			cin.clear();
			cin.ignore(999, '\n');
			Imprimir();
			//mostramos en pantalla el tablero de juego
			gotoxy(20,14);cout <<" "<<matriz[0][0]<<"  |  "<<matriz[0][1]<<"  |  "<<matriz[0][2];
			gotoxy(20,15);cout <<"---------------";
			gotoxy(20,16);cout <<" "<<matriz[1][0]<<"  |  "<<matriz[1][1]<<"  |  "<<matriz[1][2];
			gotoxy(20,17);cout <<"---------------";
			gotoxy(20,18);cout <<" "<<matriz[2][0]<<"  |  "<<matriz[2][1]<<"  |  "<<matriz[2][2];
			
			gotoxy(20,4);cout <<"Opcion incorrecta, vuelva a intentarlo: ";
			gotoxy(20,5);cout <<"Ingrese un numero del 1 al 9: ";
			cin >>num;//se guarda el nuevo dato solicitado y se evaluara de nuevo	
			}
			
			system ("cls");
			Imprimir();
			
			
			if (pj == 'x'){
				pj = 'o';
			} 
				
			else {
				pj = 'x';
			}
		}			
	}while (num != 0 && num<=9);
}

/*Creamos esta funcion ya que la necesitaremos bastantes veces, 
se encargara solamente de imprimir la tabla guia para el usuario*/
void Imprimir(){
	
	gotoxy(2,2);cout <<" 1  |  2  |  3 ";
	gotoxy(2,3);cout <<"---------------";
	gotoxy(2,4);cout <<" 4  |  5  |  6 ";
	gotoxy(2,5);cout <<"---------------";
	gotoxy(2,6);cout <<" 7  |  8  |  9 ";
	gotoxy(5,10);cout <<"Este programa fue hecho por Edgar Antonio Reyes Ceron.";
	gotoxy(44,15);cout <<"Guiese por el cuadro de la Izquierda...";
}

int main() {
	system ("color 5B");//aqui le damos color al fondo de la consola y tambien a las letras.
	tablero();//llamamos la funcion en donde trabajamos nuestro juego
	
	return 0;
}
