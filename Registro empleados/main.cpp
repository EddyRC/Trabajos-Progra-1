//Programa hecho por: Edgar Antonio Reyes Ceron
//#Carnet: RC18050

#include <iostream>//para poder utilizar cin y cout 
#include <windows.h>//para usar system("pause")
using namespace std;
//creamos una funcion que se encargara de limpiar la pantalla
void limpiar(){
	system ("cls");
}

//funcion para validar que solo se introduzcan numeros de tipo INT
int validacion(int n){
	
	while (cin.fail()) {
		limpiar();
		cin.clear();
		cin.ignore(1000, '\n');
		cout <<"Has introducido datos incorrectos, vuelve a intentarlo..."<<endl;
		cin >>n;	
	}
	return n;
}

//funcion para validar que solo se introduzcan numeros de tipo FLOAT
float validacion2(){
	float var;
	while (cin.fail()) {
		limpiar();
		cin.clear();
		cin.ignore(1000, '\n');
		cout <<"Has introducido datos incorrectos, vuelve a intentarlo..."<<endl;
		cin >>var;	
	}
	return var;
}

//estructura encargada de manejar los datos correspondientes de cada empleado
struct empleado{
	
	char cod[5];
	char nombre[50];
	int edad;
	char departamento[60];
	char puesto[60];
	float salbase;///aqui guardaremos el salario base del empleado
	float isss;
	float afp;
	float renta;
	float salliquido;
	float totalprestamo;
};

//estructura que manejara los datos de la sucursal
struct sucursal{
	int numsucursal;
	char nombresucursal[60];
}NOMBRE, NUM;//variables que posteriormente se usaran para guardar los datos de la sucursal

//funcion para calcular el descuento del ISSS
float calisss(float sal)
{	float isss = 0;

	isss = sal*0.03;
	
	return isss;
}

//funcion para calcular el descuento de AFP
float calafp(float sal){
	float afp;
	
	afp = sal * 0.0625;
	
	return afp;
}

//funcion para calcular el descuento de renta (mensual)
float calrenta(float sal){
	float renta = 0;
	
	//Para el TRAMO I
	if(sal < 472){
		renta = sal ;
	}
	//Para el TRAMO II
	else if(sal >= 472.01 && sal < 895.24){
		renta = (sal - 472)* 0.10 + 17.67;
	}
	//Para el TRAMO III
	else if(sal >= 895.24 && sal <= 2038.10){
		renta = (sal - 895.24) * 0.20 + 60;
	}
	//Para el TRAMO IV
	else if (sal > 2038.10){
		renta = (sal - 2038.10)* 0.30 + 288.57;
	}
	return renta;
}

//funcion para hacer el calculo del prestamo
float prestamo(float monto, float sal){
	float p;
	float calculo;
	calculo = sal * 0.20;
		
	if(monto < calculo){
		p = monto;
	}
	else{
		cout <<"No se puede realizar el prestamo";
		system ("pause");
	}
	
	return p;
}

int main() {
	system ("color 6B");
		
	int n;//inicializamos n como entero para guardar la cantidad de empleados
	cout <<"Introduzca el nombre de la sucursal: "<<endl;
	cin >>NOMBRE.nombresucursal;
	limpiar();
		
	cout <<"Introduzca el numero de la sucursal: "<<endl;
	cin >>NUM.numsucursal;
	validacion(n);
	limpiar();
	
	cout <<"Cuantos empleados tiene?"<<endl;
	cin >>n;
	
	n = validacion(n);//funcion encargada de validar datos
	
	limpiar();//funcion encargada de limpiar datos de la pantalla
	
	empleado e[n];/*usamos la estructura para declarar a "e" como una variable que manejara 
	todos los datos de la estructura, hacemos un arreglo dependiendo del numero de empleados
	que ingrese el usuario*/
	
	//A continuacion hacemos un ciclo for para solicitar los datos
	for(int i = 0; i < n; i++){
		
		cout <<"Ingrese el codigo de empleado: "<<endl;
		cin >>e[i].cod;
		limpiar();
		
		cout <<"Nombre del empleado: "<<endl;
		cin >>e[i].nombre;
		limpiar();
		
		cout <<"Edad:"<<endl;
		cin >>e[i].edad;
		validacion(n);
		limpiar();
		
		cout <<"Cual es el puesto del empleado? "<<endl;
		cin >>e[i].puesto;
		limpiar();
		
		cout <<"En que departamento se encuentra trabajando actualmente?"<<endl;
		cin >>e[i].departamento;
		limpiar();
		
		cout <<"Salario base: "<<endl;
		cin >>e[i].salbase;
		validacion2();
		limpiar();
		
		float monto;
		
		cout <<"Ingrese el monto del prestamo (menor al 20% del salario)"<<endl;
		cin >>monto;
		validacion2();
		limpiar ();
		e[i].totalprestamo = prestamo(monto, e[i].salbase);
		
		float calculo;
		
		e[i].isss = calisss(e[i].salbase);//hacemos el descuento del isss
		e[i].afp = calafp(e[i].salbase);//descuento de afp
		
		calculo = e[i].salbase - (e[i].afp + e[i].isss);//esto servira para calcular la renta
		
		e[i].renta = calrenta(calculo);//descuento de renta
		
		//calculo del salario liquido
		e[i].salliquido = e[i].salbase - e[i].isss - e[i].afp - e[i].renta - e[i].totalprestamo;		
	}
	
	//imprimimos los datos en pantalla
	for(int i = 0; i < n; i++){
		cout <<"\n\tEmpleado "<<i+1<<"\n";
		cout <<"Codigo del empleado: "<<e[i].cod<<endl;
		cout <<"Nombre del empleado: "<<e[i].nombre<<endl;
		cout <<"Edad: "<<e[i].edad<<endl;
		cout <<"Nombre de la sucursal en donde labora: "<<NOMBRE.nombresucursal<<endl;
		cout <<"Numero de la sucursal: "<<NUM.numsucursal<<endl;
		cout <<"Puesto del empleado: "<<e[i].puesto<<endl;
		cout <<"Departamento en donde trabaja: "<<e[i].departamento<<endl;
		cout <<"Salario base del empleado: $"<<e[i].salbase<<endl;
		cout <<"Descuento ISSS: $"<<e[i].isss<<endl;
		cout <<"Descuento AFP: $"<<e[i].afp<<endl;
		cout <<"Descuento de renta: $"<<e[i].renta<<endl;
		cout <<"Monto del prestamo solicitado por el usuario: $"<<e[i].totalprestamo<<endl;
		cout <<"Salario liquido del empleado: $"<<e[i].salliquido<<endl;	
	}
	
	return 0;
}
