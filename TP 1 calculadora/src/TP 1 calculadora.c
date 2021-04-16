/*
 ============================================================================
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado).
• Deberán contemplarse los casos de error (división por cero, etc).
• Documentar todas las funciones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Biblioteca.h"


int main(void) {

	setbuf(stdout ,NULL);

	float num1;
	float num2;
	int eleccion;
	float Suma;
	float Resta;
	float Division;
	float Producto;
	int FactorialUno;
	int FactorialDos;
	int PrimerBanderaDeControl;
	int SegundaBanderaDeControl;
	int TerceraBanderaDeControl;
	Suma = 0;
	Resta = 0;
	Division = 0;
	Producto = 0;
	FactorialUno = 0;
	FactorialDos = 0;
	PrimerBanderaDeControl = 0;
	SegundaBanderaDeControl = 0;
	TerceraBanderaDeControl = 0;

	printf("------Bienvenido a la CALCULADORA------\n");
	do{
	printf("\n    ------Ingresar opcion------    ");
	MENU();
	scanf("\n%d", &eleccion);
	if(eleccion < 1 || eleccion > 5){
		printf("\n\n<<<<<<<<Opcion no valida.>>>>>>>>>>\n\n");
	}

	switch(eleccion){
	case 1:
		printf("\nOpcion: %d\n", eleccion);
		printf("\nIngrese el primer numero: ");
		scanf("%f", &num1);
		PrimerBanderaDeControl = 1;
	break;
	case 2:
		printf("\nOpcion: %d\n", eleccion);
		printf("\nIngrese el segundo numero: ");
		scanf("%f", &num2);
		SegundaBanderaDeControl = 1;
	break;
	case 3:
		printf("\nOpcion: %d\n", eleccion);
	if(PrimerBanderaDeControl == 0 || SegundaBanderaDeControl == 0){
		printf("\nError, debe ingresar primero a las opciones 1 y 2 para poder continuar... Gracias\n");
	}else{
		printf("\n.....Aguarde un segundo......\n");

			Suma = sumar(num1, num2);
			Resta = restar(num1, num2);
			Division = dividir(num1, num2);
			Producto = multiplicar(num1, num2);
			FactorialUno = factorial(num1);
			FactorialDos = factorialDos(num2);

			TerceraBanderaDeControl = 1;
	}
	break;
	case 4:
		printf("\nOpcion: %d", eleccion);
		if(PrimerBanderaDeControl == 0 || SegundaBanderaDeControl == 0 || TerceraBanderaDeControl == 0){
		printf("\nError, debe ingresar primero a las opciones 1, 2 y 3 para poder continuar... Gracias\n");
		}else{
		printf("\n\n----------------------------------------\n");
		printf("\n\nLa suma de %.2f + %.2f es: %.2f", num1, num2, Suma);
		printf("\nLa resta de %.2f - %.2f es: %.2f", num1, num2, Resta);
		if (num2 == 0){
			printf("\nError. No es posible dividir por cero");
		}else{
		printf("\nLa division de %.2f / %.2f es: %.2f", num1, num2, Division);
		}
		printf("\nLa multiplicacion de %.2f * %.2f es: %.2f", num1, num2, Producto);
		printf("\nEl factorial de %.2f es: %d", num1, FactorialUno);
		printf("\nEl factorial de %.2f es: %d\n", num2, FactorialDos);
		printf("\n----------------------------------------\n");
		}
	break;
	case 5:
		printf("\nOpcion: %d\n", eleccion);
		printf("\nGracias por utilizar mi CALCULADORA");
	break;
	}


	}while(eleccion != 5);

	return EXIT_SUCCESS;
}
