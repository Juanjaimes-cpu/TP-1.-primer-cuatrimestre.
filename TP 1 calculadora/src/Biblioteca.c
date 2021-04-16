/*
 * Biblioteca.c
 *
 *  Created on: 15 abr. 2021
 *      Author: JuanJaimes
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int MENU()
 * @brief
 *
 * @return
 */
int MENU(){
		printf("\n\n1: Ingresar primer numero.");
		printf("\n2: Ingresar segundo numero.");
		printf("\n3: Realizar todas las operaciones.");
		printf("\n4: Mostrar resultados.");
		printf("\n5: Salir.");
		return 0;
	}

/**
 * @fn int sumar(int, int)
 * @brief
 *
 * @param NumeroUno
 * @param NumeroDos
 * @return
 */
float sumar(float NumeroUno, float NumeroDos) {
	    return NumeroUno + NumeroDos;
		  }

/**
 * @fn int restar(int, int)
 * @brief
 *
 * @param NumeroUno
 * @param NumeroDos
 * @return
 */
	  float restar(float NumeroUno, float NumeroDos) {
	    return NumeroUno - NumeroDos;
	  	  }

	  /**
	  	   * @fn float dividir(float, float)
	   * @brief
	   *
	   * @param NumeroUno
	   * @param NumeroDos
	   * @return
	   */
	  float dividir(float NumeroUno, float NumeroDos) {
	    return  NumeroUno / NumeroDos;
	  }

	  /**
	  	   * @fn int multiplicar(int, int)
	   * @brief
	   *
	   * @param NumeroUno
	   * @param NumeroDos
	   * @return
	   */
	  float multiplicar(float NumeroUno, float NumeroDos) {
	    return NumeroUno * NumeroDos;
	  }

	  /**
	  	   * @fn int factorial(int)
	   * @brief
	   *
	   * @param NumeroUno
	   * @return
	   */
	  int factorial(int NumeroUno) {

		  int FACTORIAL;
		  int ResultadoFactorialUno;
		  FACTORIAL = 1;
		  ResultadoFactorialUno = 1;

		 while(FACTORIAL < NumeroUno){
			 ResultadoFactorialUno = ResultadoFactorialUno * (NumeroUno * FACTORIAL);
			 NumeroUno--;
		 }
		 return (int)ResultadoFactorialUno;
	  }

	  /**
	  	   * @fn int factorialDos(int)
	   * @brief
	   *
	   * @param NumeroDos
	   * @return
	   */
	  int factorialDos(int NumeroDos){
		  int FACTORIALDOS;
		  int ResultadoFactorialDos;
		  FACTORIALDOS = 1;
 		  ResultadoFactorialDos = 1;

		  while(FACTORIALDOS < NumeroDos){
		  	ResultadoFactorialDos = ResultadoFactorialDos * (NumeroDos * FACTORIALDOS);
		  	 NumeroDos--;
		 }
		  	 return (int)ResultadoFactorialDos;
}

#ifndef BIBLIOTECA_C_
#define BIBLIOTECA_C_

#endif /* BIBLIOTECA_C_ */
