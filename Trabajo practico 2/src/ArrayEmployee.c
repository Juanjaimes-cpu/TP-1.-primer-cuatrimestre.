/*
 * ArrayEmployee.c
 *
 *  Created on: 5 may. 2021
 *      Author: Juan Jaimes
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

/**
 * @struct
 * @brief
 *
 */
typedef struct {
	int idSector;
	char descripcion[51];
}eSector;




/**
 * @struct
 * @brief
 *
 */
typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;
	int isEmpty;
	}eEmployee;

/**
 * @fn int MENU()
 * @brief
 *
 * @return
 */
int MENU(){
			printf("\n1.ALTA producto\n");
			printf("2.MODIFICAR producto\n");
			printf("3.BAJA producto\n");
			printf("4.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
			printf("5.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
			printf("6.Salir.");
			return 0;
}

/**
 */
int eEmployee_idSubida = 0;
/**
 * @fn int eProducto_ObtenerID()
 * @brief
 *
 * @return
 */
int eEmployee_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return eEmployee_idSubida += 1;
}


/**
 * @fn void initEmployees(eEmployee[], int)
 * @brief
 *
 * @param Lista
 * @param TAM
 */
void eEmployee_Inicializar(eEmployee Lista[], int TAM)
{
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			Lista[i].isEmpty = LIBRE;
		}
	}
}


int BuscarLibre(eEmployee lista[], int TAM)
{
    int i;
    int index = -1;//Fuera de array
    for(i=0; i<TAM; i++)
    {
        if(lista[i].isEmpty==LIBRE)//encontre lugar
        {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * @fn int eEmployee_ObtenerIndexLibre(eEmployee[], int)
 * @brief
 *
 * @param Lista
 * @param TAM
 * @return
 */
int eEmployee_ObtenerIndexLibre(eEmployee Lista[], int TAM) {
	int retorno = -1;
	int i;


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (Lista[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/**
 * @fn int eEmployee_BuscarPorID(eEmployee[], int, int)
 * @brief
 *
 * @param Lista
 * @param TAM
 * @param ID
 * @return
 */
int eEmployee_BuscarPorID(eEmployee Lista[], int TAM, int ID) {
	int retorno = -1;
	int i;


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {

			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (Lista[i].isEmpty == OCUPADO && Lista[i].id == ID)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * @fn int CargareEmployee(eEmployee[], int)
 * @brief
 *
 * @param lista
 * @param TAM
 * @return
 */


/*
int CargareEmployee(eEmployee lista[], int TAM)
{
	 int i;
	    i = eEmployee_ObtenerIndexLibre(lista, TAM);
	    if(i!=-1)
	    {
	        lista[i] = eEmployee_CargarDatos();
	        lista[i].isEmpty = OCUPADO;
	    }
	    return i;
	}*/



eEmployee eEmployee_CargarDatos() {
		eEmployee auxiliar;

		utn_getPalabra(auxiliar.name ,sizeof(auxiliar.name), "\nIngrese el nombre: \n", "\nERROR: Ingrese sólo letras. \n", 5);
		utn_getPalabra(auxiliar.lastName ,sizeof(auxiliar.lastName ), "\nIngrese el apellido: \n", "\nERROR: Ingrese sólo letras. \n", 5);
		utn_getNumeroFlotante(&auxiliar.salary,"\nIngrese salario: \n","\nERROR: Ingrese salario válido.\n",1,99999,5);
		utn_getNumero(&auxiliar.idSector,"\nIngrese sector: \n","\nERROR: Ingrese sector válido.\n",1,100,5);

	    auxiliar.isEmpty = OCUPADO;

		return auxiliar;
	}



/**
 * @fn int eEmployee_Alta(eEmployee[], int)
 * @brief
 *
 * @param Lista
 * @param TAM
 * @return
 */
int  eEmployee_Alta(eEmployee Lista[], int TAM, eSector ListaSector[], int TSEC ) {
	int retorno = 0;
	eEmployee auxeEmployee;

	//BUSCO ESPACIO EN ARRAY
	int index = eEmployee_ObtenerIndexLibre(Lista, TAM);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Producto AUXILIAR
		auxeEmployee = eEmployee_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxeEmployee.id = eEmployee_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxeEmployee.isEmpty = OCUPADO;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		Lista[index] = auxeEmployee;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}






int  eEmployee_Baja(eEmployee Lista[], int TAM, eSector ListaSector[], int TSEC) {
	int empleadoIngresado;
	int i;


	eEmployee_MostrarTodos(Lista, TAM, ListaSector, TSEC);
	//LISTO TODOS LOS eEmployee
	printf("Ingrese ID del empleado que desee dar de BAJA: \n");
		scanf("%d", &empleadoIngresado);

		for(i=0; i<TAM; i++)
		{
			if(empleadoIngresado == Lista[i].id)
			{
				Lista[i].isEmpty = LIBRE;
				break;
				}
				else
				{
				printf("\nEL id del producto que ingreso no existe.");
			}
		}
		return 0;
}

void modificarEmpleado(eEmployee empleado[], int T, eSector Sector[], int TSEC)
{
	int modificacion;
	int empleadoIngresado;
	int i;
	int j;
	int x;

	 for(i=0; i<T ; i++)
		    {
		    if(empleado[i].isEmpty == OCUPADO)
		    {
		    	eEmployee_MostrarTodos(empleado, T, Sector, TSEC);
		    }
		    }
	 	 	 for(j=0; j<T; j++)
	 	    	 {
	 	    	 for(x=0; x<TSEC; x++)
	 	    	 {
				 printf("Ingrese ID del empleado que quiera modificar: \n");
				 scanf("%d", &empleadoIngresado);

	do{
		printf("\nOpcion a modificar: ************************************\n"
			   "1. Nombre.\n"
			   "2. Apellido.\n"
			   "3. Salario.\n"
			   "4. Sector.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
				scanf("%d", &modificacion);

		switch(modificacion)
		{
			case 1:
				utn_getPalabra(empleado[j].name ,sizeof(empleado[j].name), "\nIngrese nuevo nombre: \n", "\nERROR: Ingrese sólo letras. \n", 10);
			break;

			case 2:
				utn_getPalabra(empleado[j].lastName ,sizeof(empleado[j].lastName ), "\nIngrese nuevo apellido: \n", "\nERROR: Ingrese sólo letras. \n", 10);
			break;

			case 3:
				utn_getNumeroFlotante(&empleado[j].salary,"\nIngrese salario: \n","\nERROR: Ingrese nuevo salario válido.\n",100,999999,10);
			break;

			case 4:
				utn_getNumero(&Sector[x].idSector,"\nIngrese sector: \n","\nERROR: Ingrese nuevo sector válido.\n",1,100,10);
			break;
		}
	}while(modificacion!=0);

	empleado[j].isEmpty = OCUPADO;
	 	    	 }
	 	    	 }
}

/**
 * @fn void eEmployee_MostrarUno(eEmployee)
 * @brief
 *
 * @param Lista
 */
void eEmployee_MostrarUno(eEmployee Lista)
{
	if(Lista.isEmpty == OCUPADO)
	{
	printf("\nID: %d\n NOMBRE: %s\n APELLIDO: %s\n SALARIO: %f\n SECTOR: %d \n\n", 	  Lista.id,
																					  Lista.name,
																					  Lista.lastName,
																					  Lista.salary,
																					  Lista.idSector
																					  );
			}
}

/**
 * @fn int eEmployee_MostrarTodos(eEmployee[], int, eSector[], int)
 * @brief
 *
 * @param Lista
 * @param TAM
 * @param ListaSector
 * @param SEC
 * @return
 */
void eEmployee_MostrarTodos(eEmployee Lista[], int TAM, eSector ListaSector[], int TSEC)
{
	int i;
	int j;
	if (Lista != NULL && TAM > 0)
	{
		//RECORRO EL ARRAY
		for (i=0; i<TAM; i++)
		{
			for (j=0; j<TAM; j++)
			{
			//PREGUNTO POR SU ESTADO "OCUPADO"
				if (Lista[i].isEmpty == OCUPADO)
				{
				if(Lista[i].idSector == ListaSector[j].idSector)
				{
		printf("\nid: %d\n   NOMBRE: %s\n   APELLIDO: %s\n   SALARIO: %f\n   SECTOR: %s\n",    	Lista[i].id,
																								Lista[i].name,
																								Lista[i].lastName,
																								Lista[i].salary,
																								ListaSector[j].descripcion);
																								break;
					}
				}
			}
		}
	}
}

void informes(eEmployee lista[], int TAM)
{
	int   i;
	float acumuladorS    = 0;
	int   contadorE      = 0;
	int   superaPromedio = 0;
	float promedio;

	if(lista != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				acumuladorS = acumuladorS + lista[i].salary;
				contadorE ++;
			}
		}
	}

	promedio = acumuladorS / contadorE;

	printf("PROMEDIO DE SUELDOS: %.2f\n", promedio);
	printf("SUMA TOTAL DE SALARIOS: %.2f\n", acumuladorS);

	for(i = 0; i < TAM; i++)
	{
		if(lista[i].salary > promedio)
		{
			superaPromedio ++;
		}
	}
	printf("Empleados con sueldo por encima del promedio: %d \n", superaPromedio);
}


void ordenamiento(eEmployee listaEmpleados[], int TAM)
{
	int i;
	int j;

	eEmployee auxiliarProducto;

	    for(i=0; i<TAM-1; i++)
	    {
	        for(j=i+1; j<TAM; j++)
	        {
	            if(strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName)>0)
	            {
	                auxiliarProducto = listaEmpleados[i];
	                listaEmpleados[i] = listaEmpleados[j];
	                listaEmpleados[j] = auxiliarProducto;
	            }
	        }
		}
}






