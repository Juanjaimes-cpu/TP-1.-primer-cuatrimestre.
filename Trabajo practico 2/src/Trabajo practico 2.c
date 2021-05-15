/*
 ============================================================================
 TRABAJO PRACTICO N°2.

 Jaimes Juan.

 DNI: 40.422.634

 Divicion: Primero B.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define OCUPADO 1
#define VACIO 0
#define T 3
#define TS 4

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int retorno;
	int BanderaDeControl;
	retorno = 0;
	BanderaDeControl = 0;

	eEmployee empleados[T];
	eSector sectores[TS]={{1,"Sistemas"},{2,"Seguridad"},{3,"RRHH"},{4,"Ventas"}};
	eEmployee_MostrarTodos(empleados, T, sectores, TS);

	eEmployee_Inicializar(empleados, T);



do{
		MENU();
		printf("Elija una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			//ALTA
			retorno =  eEmployee_Alta(empleados, T, sectores, TS);
				        	 if(retorno != -1)
				        	 {
				        	 printf("\n\nEmpleado ingresado con exito!!!\n\n");
				        	// eEmployee_MostrarUno(empleados[retorno]);
				        	 }else{
				        	 printf("\n\nNo hay mas lugar en la lista!!\n\n");
				        	 }
				        	 BanderaDeControl = 1;
				        	 system("pause");
			break;
		case 2:
			if(BanderaDeControl == 0){
											printf("\nError, debe ingresar primero a la opcion 1 para poder continuar... Gracias\n");
										}else{
											modificarEmpleado(empleados, T, sectores, TS);
										}
					break;

		case 3:
			//BAJA
						if(BanderaDeControl == 0){
								printf("\nError, debe ingresar primero a la opcion 1 para poder continuar... Gracias\n");
							}else{
							if(eEmployee_Baja(empleados, T, sectores, TS)) {
							puts("\n * BAJA DE Empleado EXITOSA");
						} else {
							puts("\n * BAJA DE Empleado CANCELADA");
						}
						system("pause");
							}
						break;
		case 4:
			if(BanderaDeControl == 0){
								printf("\nError, debe ingresar primero a la opcion 1 para poder continuar... Gracias\n");
							}else{
								eEmployee_MostrarTodos(empleados, T, sectores, TS);
								system("pause");
							}
		break;
		case 5:
			ordenamiento(empleados, T);
			eEmployee_MostrarTodos(empleados, T, sectores, TS);
		break;
		case 6:
			informes(empleados, T);
		break;
		default:
		printf("Opcion invalida! La opcion [%d] no existe\n", opcion);
		printf("\n");
							}

}while(opcion!=6);


return 0;


return EXIT_SUCCESS;

}
