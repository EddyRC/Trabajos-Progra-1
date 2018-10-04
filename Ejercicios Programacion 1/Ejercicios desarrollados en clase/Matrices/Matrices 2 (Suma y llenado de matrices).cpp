#include <iostream>

using namespace std;

int main() {
	
	//SUMA DE MATRICES
	/*int mat[5][5];//inicializamos la matriz
	int mat2[5][5];//inicializamos la matriz
	int mat3[5][5];//inicializamos la matriz
	
	for (int fila = 0; fila < 5; fila++)//para recorrer las filas de la matriz (tener el control de las filas)
	{
		for (int col = 0; col < 5; col++)//para recorrer las columnas de la matriz (tener el control de las filas)
		{
			mat[fila][col]= 0;//aqui llenamos de datos de la matriz (los que queramos)
			
			if (fila == 4 || col == 2)
			{
				mat2[fila][col] = 0;
				//mat2[fila][col] = 0;
			}
			else 
			{
				mat2[fila][col]=1;
			}
			//sumamos la matriz
			mat3[fila][col] = mat[fila][col] + mat2[fila][col];//sumamos las matrices
		}
		//cout <<endl;
	}
	
	
	cout <<"RESULTADO"<<endl;
	
	for (int fila = 0; fila < 5; fila++)
	{		
		for (int col = 0; col < 5; col++)
		{
			cout << mat3[fila][col];//mostramos en pantalla la matriz
		}
		cout<<endl;
	}*/
	
	
	
	/*LLENAR UNA MATRIZ CON NUMEROS INTERCALADOS
	
	int mat[5][5];//inicializamos la matriz
	int mat2[5][5];//inicializamos la matriz
	int mat3[5][5];//inicializamos la matriz
	
	for (int fila = 0; fila < 5; fila++)//para recorrer las filas de la matriz (tener el control de las filas)
	{
		for (int col = 0; col < 5; col++)//para recorrer las columnas de la matriz (tener el control de las filas)
		{
			
			if (fila == col || fila % 2 == 0 && col % 2 == 0 || fila % 2 == 1 && col % 2 == 1)
			{
				mat3[fila][col] = 0;		
			}
			else 
			{
				mat3[fila][col]=1;
			}
		}
	}
	

	cout <<"RESULTADO"<<endl;
	
	for (int fila = 0; fila < 5; fila++)
	{		
		for (int col = 0; col < 5; col++)
		{
			cout << mat3[fila][col]<<" ";//mostramos en pantalla la matriz
		}
		cout<<endl;
	}*/
	
	
	
	return 0;
}
