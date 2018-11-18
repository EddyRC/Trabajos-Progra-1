/*
Programa realizado por:
    Edgar Antonio Reyes Ceron.
# de Carnet:
   RC18050.
Ultima actualizacion:
	Sabado 17 de Noviembre de 2018
*/

#include <cstdlib>
#include <iostream>
#include <winsock2.h>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;

void connrealizada();//funcion para informar de que la conexion si se realizo
void mostrarclientes();//funcion encargada de mostrar los clientes de la base de datos
void mostrarventas();//funcion encargada de mostrar lal ventas de la base de datos
void mostrarproductos();//funcion encargada de mostrar los productos de la base de datos
void mostrarcotizaciones();//funcion encargada de mostrar las cotizaciones de la base de datos

//Funcion principal main
int main() {
	
	int opc;
    do{
    	cout<<"Bienvenido, seleccione una opcion: "<<endl;
		cout<<"1- Mostrar clientes."<<endl;
		cout<<"2- Mostrar ventas."<<endl;
    	cout<<"3- Mostrar productos."<<endl;
    	cout<<"4- Mostrar cotizaciones."<<endl;
    	cout<<"5- Salir"<<endl;
    	cin>>opc;
    	system("cls");
		switch(opc){
    		case 1:mostrarclientes();
    			system("pause");
    			system("cls");
				break;
    		case 2:mostrarventas();
    			system("pause");
    			system("cls");
    			break;
    		case 3:mostrarproductos();
    			system("pause");
    			system("cls");
    			break;
    		case 4:mostrarcotizaciones();
    			system("pause");
    			system("cls");
    			break;
    		case 5: break;
		}
	}while(opc!=5);
	return 0;
}

//para informar que la conexion se ha establecido
void connrealizada(){
	cout<<"Se ha conectado satisfactoriamente a la base de datos..."<<endl;
    system("pause");
    system("cls");
}
//para mostrar los clientes
void mostrarclientes(){

	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    //condicional que nos servira para mostrar un error si no se pudo conectar a la base de datos
    if(conn==NULL){  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");
    }
    connrealizada();
    //solicitamos datos de la tabla clientes
    mysql_query(conn,"select * from clientes");
    res=mysql_store_result(conn);
    
    //mostramos en pantalla los registros de las tablas
    cout<<"\tTABLA CLIENTES\t"<<endl;
    while((row=mysql_fetch_row(res))!=NULL)
    {
        cout<<"codcliente: "<<row[0]<<"\t";
        cout<<"nombre: "<<row[1]<<"\t";
        cout<<"apellido: "<<row[2]<<"\t";
        cout<<"tel: "<<row[3]<<"\n";
    }
    //cerramos la conexion con la base de datos
	mysql_close(conn);
}
//para mostrar las ventas
void mostrarventas(){

	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    //condicional que nos servira para mostrar un error si no se pudo conectar a la base de datos
    if(conn==NULL){  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");
    }
    connrealizada();
    //solicitamos datos de la tabla ventas
    mysql_query(conn,"select * from ventas");
    res=mysql_store_result(conn);
    
    //mostramos en pantalla los registros de las tablas
    cout<<"\tTABLA VENTAS\t"<<endl;
    while((row=mysql_fetch_row(res))!=NULL)
    {
    	
        cout<<"codventa: "<<row[0]<<"\t";
        cout<<"codpro: "<<row[1]<<"\t";
        cout<<"cantidad: "<<row[2]<<"\t";
        cout<<"fecha: "<<row[3]<<"\t";
        cout<<"codcliente: "<<row[4]<<"\n";
    }
    //cerramos la conexion con la base de datos
	mysql_close(conn);
}
//para mostrar productos
void mostrarproductos(){
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    //condicional que nos servira para mostrar un error si no se pudo conectar a la base de datos
    if(conn==NULL){  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");
    }
    connrealizada();
    //solicitamos datos de la tabla productos
    mysql_query(conn,"select * from productos");
    res=mysql_store_result(conn);
    
    //mostramos en pantalla los registros de las tablas
    cout<<"\tTABLA PRODUCTOS\t"<<endl;
    while((row=mysql_fetch_row(res))!=NULL)
    {
        cout<<"codpro: "<<row[0]<<"\t";
        cout<<"nombre: "<<row[1]<<"\t";
        cout<<"precio: $"<<row[2]<<"\t";
        cout<<"existencias: "<<row[3]<<"\t";
        cout<<"fecha de ingreso: "<<row[4]<<"\n";
    }
    //cerramos la conexion con la base de datos
	mysql_close(conn);
}
//para mostrar las cotizaciones
void mostrarcotizaciones(){
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    //condicional que nos servira para mostrar un error si no se pudo conectar a la base de datos
    if(conn==NULL){  
		cout<<mysql_error(&mysql)<<endl;
    	system("pause");
    }
    connrealizada();
    
    //solicitamos datos de la tabla cotizaciones
    mysql_query(conn,"select * from cotizaciones");
    res=mysql_store_result(conn);
    
    //mostramos en pantalla los registros de las tablas
    cout<<"\tTABLA COTIZACIONES\t"<<endl;
    while((row=mysql_fetch_row(res))!=NULL)
    {
        cout<<"codcotizacion: "<<row[0]<<"\t";
        cout<<"codproducto: "<<row[1]<<"\t";
        cout<<"codcliente: "<<row[2]<<"\t";
        cout<<"fecha de cotizacion: "<<row[3]<<"\n";
    }
    //cerramos la conexion con la base de datos
	mysql_close(conn);
}
