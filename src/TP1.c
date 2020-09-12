/* ============================================================================
 Name        : TP1.c
 Author      : Federico Waicen
 Division    : E
 Description : Calculadora con funciones y bibliotecas.
 ============================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils_UTN.h"

int main(void) {
	setbuf(stdout, NULL);
	int operando1, operando2, opcion = 0;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	int resulSuma, resulResta, resulMult, resulFac1, resulFac2;
	float resulDiv;
	char seguir = 's';

	do {
		printf("\n============CALCULADORA=============\n");
		printf("Por favor ingrese una opción del menú: \n");
		printf("1) Ingresar el primer operando\n");
		printf("2) Ingresar el segundo operando\n");
		printf("3) Generar calculos\n");
		printf("4) Mostrar resultados\n");
		printf("5) Salir\n");
		printf("Opción:");
		scanf("%d", &opcion);

		while(opcion > 5 || opcion < 1)
		{
			printf("Error! Ingrese una opción valida del menú :");
			scanf("%d", &opcion);
		}

		switch(opcion)
		{
			case 1:
				flag1 = 1;
				operando1 = ingresarOperando();
				printf("-------------------------------");
				printf("\n Primer Operando = %d \n", operando1);
				printf("-------------------------------");
				break;
			case 2:
				flag2 = 1;
				operando2 = ingresarOperando();
				printf("-------------------------------");
				printf("\n Segundo Operando = %d \n", operando2);
				printf("-------------------------------");
				break;
			case 3:
				if (flag1 == 0 || flag2 == 0)
				{
					printf("\nError! Para continuar ingrese 2(dos) operandos :");
				}
				else
				{
					flag3 = 1;
					resulSuma  = sumar(operando1, operando2);
					resulResta = restar(operando1, operando2);
					resulMult  = multiplicar(operando1, operando2);
					resulFac1  = factorial(operando1);
					resulFac2  = factorial(operando2);
					printf("\nCalculado, LISTO PARA MOSTRAR -\n");
				}
				break;
			case 4:
				if(flag1 == 0 || flag2 == 0)
				{
					printf("\nNo puede mostrar un resultado sin operandos, ingreselos por favor\n");
				}
				else if (flag3 == 0)
				{
					printf("\nNo puede mostrar un resultado porque no generó los calculos, por favor vuelva a intentar\n");
				}
				else
				{
					printf("\n============RESULTADOS============");
					printf("\n Primer Operando = %d		Segundo Operando = %d ", operando1, operando2);
					printf("\nLa suma es: %d", resulSuma);
					printf("\nLa resta es: %d", resulResta);
					printf("\nLa multiplicacion: %d", resulMult);
					printf("\nEl factorial de %d es: %d y el de %d: %d",
							operando1, resulFac1, operando2, resulFac2);

					if(operando2 == 0)
					{
						printf("\nError! No se puede dividir por < 0 > \n");
					}
					if(operando2 > 0)
					{
						resulDiv = dividir(operando1, operando2);
						printf("\nResultado de division es %.2f\n", resulDiv);
						printf("Desea continunar? S(si)/ N(no):");
						fflush(stdin);
						scanf("%c", &seguir);
					}
				}
				break;
			case 5:
				if(flag1 == 0|| flag2 == 0 || flag3 == 0)
				{
					printf("No quiere relizar algun calculo? S(si)/ N(no):");
					fflush(stdin);
					scanf("%c", &seguir);
				}
				else
				{
					printf("Desea hacer un calculo más? S(si)/ N(no):");
					fflush(stdin);
					scanf("%c", &seguir);
				}
		}
		seguir = tolower(seguir);
	}
    while(seguir == 's');

	printf("\nAdiós !");
	return EXIT_SUCCESS;
}

