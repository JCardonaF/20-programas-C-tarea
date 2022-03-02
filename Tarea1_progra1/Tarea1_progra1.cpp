#include "stdafx.h" //se geneara automaticamente
#include <iostream>  //activa funciones de entrada y salida como cin, cout, para pedir datos y mandar mensajes
#include <conio.h> //activa funciones como print, cprint, textcolor para backgrouds.
#include <Windows.h> 
#include <ctype.h> //Nos permita usar la funcion toupper
#include <cmath> //libreria para realizar funciones matematicas, como raiz cuadrada, potencias, senos, cosenos, etc.
#include <stdlib.h> // para poder usar la funcion "exit, abort o return"
using namespace std;

void gotoxy(int x, int y) // rutina para movimiento del cursor en toda la pantalla
{
	COORD coord;
	coord.X = (SHORT)x-1;
	coord.Y = (SHORT)y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Declaracion de variables publicas

int matrizsig[2][4];
int i,j; //i=para recorrido de filas, j=para recorrido de columnas
char p;
int opcion, fila, columna, num0y50=0, num80y120=0, num200=0, punt, punti,puntj;

void Triangulo(float*lad1, float*lad2, float*lad3, float*areat, float*perimt, float*semiper)
{
	system("cls"); system("color f2");
	gotoxy(20,4); cout <<" **** CALCULO DEL AREA Y PERIMETRO DE UN TRIANGULO ****";
	gotoxy(8,8); cout <<"Ingrese el PRIMER lado del triangulo______: ", cin>>*lad1; gotoxy(57,8);cout<<"Unidades";
	gotoxy(8,10); cout <<"Ingrese el SEGUNDO lado del triangulo_____: "; cin>>*lad2; gotoxy(57,10);cout<<"Unidades";
	gotoxy(8,12); cout <<"Ingrese el TERCER lado del triangulo______: "; cin>>*lad3; gotoxy(57,12);cout<<"Unidades";

	//Calculando el perimetro:
	*perimt = *lad1 + *lad2 + *lad3;
	//Calculando el area, Use la formula de "HERON" para el calculo del area
	*semiper=*perimt/2; //aca calculamos el semiperimetro que es la mitad del perimetro.
	*areat= sqrt ((*semiper*(*semiper- *lad1)*(*semiper- *lad2)*(*semiper- *lad3)));

	gotoxy(25,16); cout<<"****** RESULTADOS ******"; 
	gotoxy(15,18); _cprintf("EL PERIMETRO DEL TRIANGULO ES DE: %8.2f",*perimt); printf("  Unidades"); 
	gotoxy(15,20); _cprintf("EL AREA DEL TRIANGULO ES DE ____: %8.2f",*areat); printf("  Unidades Cuadradas");

}

// ----------- MENU MATRIZ SIGMA --------------
void MatrizSigma()//int *matrizsig[2][4])
	{
		
		system("cls"); system("color f3");
		gotoxy(35,2); cout<<" **** MATRIZ SIGMA **** ";
		fila=4;
		columna=15;
		gotoxy(8,4); cout<<"INGRESE DATOS DE LA MATRIZ SIGMA";
		for (i=0;i<2;i++)
			{
				for  (j=0;j<4;j++)
				{
					gotoxy(columna+(j*8),fila+(i+2)); cin>> matrizsig[i][j];
				}
			}
	
		//---- Buscando los numeros menores o iguales a 50
		num0y50 = matrizsig[0][0];
		for(i=0;i<2; i++)
		 {
			for(j=0; j<4; j++)
			{
				if (matrizsig [i][j] <= 50)// && (matrizsig[i][j] <= 50))
			 {
					num0y50 = matrizsig [i][j];
				gotoxy(8,10); cout<<"Los numeros menores o igual a 50 son ------:";
				gotoxy(15+(j*8),12+i); cout<< num0y50;
				}
			 }
			}
		//---- Buscando los numeros entre 80 y 120
		num80y120 = matrizsig[0][0];
		for(i=0;i<2; i++)
		{
			for(j=0; j<4; j++)
			{
				if ((matrizsig [i][j] >= 80) && (matrizsig[i][j] <= 120))
					{
					num80y120 = matrizsig[i][j];
					gotoxy(8,15); cout<<"Los numeros comprendidos entre 80 y 120 son:";
					gotoxy(15+(j*8),17+i); cout<< num80y120;
					}
			 }
		}
		//---- Buscando mayores que 200
		num200 = matrizsig[0][0];
		for(i=0;i<2; i++)
		{
			for(j=0; j<4; j++)
			{
				if (matrizsig [i][j] > 200)					{
					num200 = matrizsig[i][j];
					gotoxy(8,20); cout<<"Los numeros mayores a 200 son -------------:";
					gotoxy(15+(j*8),22+i); cout<< num200;
					gotoxy(8,24);cout<<"_______________________________________________________________________________________________________________";
					}
			 }
		}
}

void Visualizar(float*lad1, float*lad2, float*lad3,float*areat, float*perimt, float*semiper)// int matrizsig[2][4])
{
	system("cls"); system("color f8");
	gotoxy(25,1); cout<<" **** VISUALIZACION GENERAL DE DATOS ****";
	gotoxy(10,3); cout<<"Datos del Triangulo ______________________________________________________ :";
	gotoxy(15,5); printf("El PRIMER Lado del TRIANGULO mide: "); 
	gotoxy(53,5); printf("%5.2f",*lad1); gotoxy(60,5);cout<<"Unidades";
	gotoxy(15,6); printf("El SEGUNDO Lado del TRIANGULO mide: ");
	gotoxy(53,6); printf("%5.2f",*lad2); gotoxy(60,6);cout<<"Unidades";
	gotoxy(15,7); printf("El TERCER Lado del TRIANGULO mide: ");
	gotoxy(53,7); printf("%5.2f",*lad3); gotoxy(60,7);cout<<"Unidades";
	gotoxy(15,8); printf("El PERIMETRO del TRIANGULO mide: ");
	gotoxy(53,8); printf("%5.2f",*perimt); gotoxy(60,8);cout<<"Unidades";
	gotoxy(15,9); printf("El AREA del TRIANGULO mide: ");
	gotoxy(53,9); printf("%5.2f",*areat); gotoxy(60,9);cout<<"Unidades Cuadradas";
	gotoxy(10,11); cout<<"Datos de la Matriz Sigma __________________________________________________:";
		fila=11;
		columna=15;
			for (i=0;i<2;i++)
			{
				for  (j=0;j<4;j++)
				{
				gotoxy(columna+(j*8),fila+(i+2)); cout<< matrizsig[i][j];
				}
			}
			num0y50 = matrizsig[0][0];
		for(i=0;i<2; i++)
		 {
			for(j=0; j<4; j++)
			{
				if (matrizsig [i][j] <= 50)// && (matrizsig[i][j] <= 50))
			 {
				num0y50 = matrizsig [i][j];
				gotoxy(8,15); cout<<"Los numeros menores o igual a 50 son ------:";
				gotoxy(15+(j*8),16+i); cout<< num0y50;
				}
			 }
			}
		num80y120 = matrizsig[0][0];
		for(i=0;i<2; i++)
		{
			for(j=0; j<4; j++)
			{
				if ((matrizsig [i][j] >= 80) && (matrizsig[i][j] <= 120))
					{
					num80y120 = matrizsig[i][j];
					gotoxy(8,18); cout<<"Los numeros comprendidos entre 80 y 120 son:";
					gotoxy(15+(j*8),19+i); cout<< num80y120;
					}
			 }
		}
		num200 = matrizsig[0][0];
		for(i=0;i<2; i++)
		{
			for(j=0; j<4; j++)
			{
				if (matrizsig [i][j] > 200)					{
					num200 = matrizsig[i][j];
					gotoxy(8,21); cout<<"Los numeros mayores a 200 son -------------:";
					gotoxy(15+(j*8),22+i); cout<< num200;
					gotoxy(8,24);cout<<"_______________________________________________________________________________________________________________";
					}
			 }
		}

}
	 
	
// ---------- MENU PRICIPAL DEL PROGRAMA -----------
void menu()
{
	system("cls"); system("color f1");
	gotoxy(35,5); cout<<"**** BIENVENIDO AL MENU PRINCIPAL ****";
	gotoxy(40,6); cout<<"****** 20 PROGRAMAS ******";
	gotoxy(45,8); cout<<"ELIJA LA OPCION [ ]:";
	gotoxy(25,12); cout<<"1. SUMA, RESTA, MULTIPLICACION Y DIVISION DE 2 NUMEROS";
	gotoxy(25,12); cout<<"2. DETERMINAR SI UN NUMERO ES PAR O IMPAR";
	gotoxy(25,13); cout<<"3. CONVERSION DE MEDIDAS";
	gotoxy(25,14); cout<<"4. Determinar si una palabra o un número es palíndromo.";
	gotoxy(25,14); cout<<"5. Conversión de números arábigos a romanos";
	gotoxy(25,14); cout<<"6. Conversión de números enteros a letras";
	gotoxy(25,14); cout<<"7. Conversión de números enteros con decimal a letras";
	gotoxy(25,14); cout<<"8. UNA Tabla de multiplicar";
	gotoxy(25,14); cout<<"9. Todas las tablas de multiplicar del 1 al 10";
	gotoxy(25,14); cout<<"10. Crear de forma grafica la multiplicacion manual";
	gotoxy(25,14); cout<<"11. Conversion de numeros decimales a binario";
	gotoxy(25,14); cout<<"12. Conversión de números decimales a hexadecimales";
	gotoxy(25,14); cout<<"13. Crear Figuras Geometricas Basicas";
	gotoxy(25,14); cout<<"14. Mover un punto en toda la pantalla";
	gotoxy(25,14); cout<<"15. Simulacion de un Cajero (Automata)";
	gotoxy(25,14); cout<<"16. Calcular la hipotenusa";
	gotoxy(25,14); cout<<"5. Conversión de números arábigos a romanos";
	gotoxy(25,16); cout<<"6. SALIR DEL PROGRAMA";
}

// -------------- OPCION REGRESAR A MENU PRICIPAL ---------------
void Regresar()
{
	{
	p = 'N';
    gotoxy (20, 25); _cprintf("DESEA REGRESAR Al MENU PRINCIPAL: (S/N):  [   ]");  
    gotoxy (31, 27); cout<<"S/s = SI, Regresar al menu pricipal";
	gotoxy (31, 28); cout<<"N/n = NO, Salir del programa";
	gotoxy(64,25); cin>> p; 
	p = toupper(p);
	}while (p == 'N')
	{exit(0);}
	}

//--------------- PROCEDIMIENTO PRINCIPAL ---------
void main()
{
	float lad1,lad2,lad3,areat, perimt,semiper;
	do
	{
		menu();
	    gotoxy(62,8); cin >> opcion;
	    switch (opcion)
	    {
			case 1:
			{
				Triangulo(&lad1, &lad2, &lad3, &areat, &perimt, &semiper); //aqui invocamos la opcion del triangulo
	     		Regresar(); //aqui invocamos la opcion regresar para preguntar si desea regresar al menu principal.
			}
			break;
			case 2:
			{
				MatrizSigma();//&matrizsig[2][4]);
				Regresar();
			}
			break;
			case 3:
			{
				Visualizar(&lad1, &lad2, &lad3, &areat, &perimt, &semiper); //&matrizsig[2][4]);
				Regresar();
			}
			break;
		}
	}while (opcion != 4);
}
