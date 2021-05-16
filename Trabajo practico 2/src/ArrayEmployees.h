/*
 * ArrayEmployees.h
 *
 *  Created on: 5 may. 2021
 *      Author: Juan Jaimes
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct {
	int idSector;
	char descripcion[51];
}eSector;

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;
	int isEmpty;
	}eEmployee;

int MENU();

int sortEmployees(eEmployee[], int, int);

int eEmployee_idSubida;
int eEmployee_ObtenerID();
void eEmployee_Inicializar(eEmployee[], int);
int eEmployee_ObtenerIndexLibre(eEmployee[], int TAM);
int BuscarLibre(eEmployee lista[], int TAM);
int eEmployee_BuscarPorID(eEmployee[], int TAM, int ID);
int eEmployee_Alta(eEmployee[], int TAM, eSector[], int TSEC);
int CargareEmployee(eEmployee[], int TAM);
int eEmployee_Baja(eEmployee[], int, eSector[], int);
void eEmployee_MostrarUno(eEmployee);
void eEmployee_MostrarTodos(eEmployee Lista[], int TAM, eSector ListaSector[], int TSEC);
eEmployee eEmployee_CargarDatos();
void modificarEmpleado(eEmployee[], int, eSector[], int);
void ordenamiento(eEmployee[], int TAM);
void informes(eEmployee[], int TAM);


#endif /* ARRAYEMPLOYEES_H_ */
