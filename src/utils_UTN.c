/* ============================================================================
 Name        : utils_UTN.c
 Author      : Federico Waicen
 Division    : E
 Description : Funciones
 ============================================================*/
#include <stdio.h>
#include <stdlib.h>

int sumar(int a,int b)
{
	return (a + b);
}

int restar(int a,int b)
{
    return (a - b);
}

float dividir(float a,int b)
{
	return (a / b);
}

int multiplicar(int a,int b)
{
	return (a * b);
}

int factorial(int x)
{
	int cont, fac=1;

	if(x < 0) //por si el número llega a ser negativo
	{
		x *= -1;
	}

	for(cont = 1; cont <= x ; cont++)
	{
		fac *= cont;
	}

	return fac;
}

int ingresarOperando() {
	int numero = 0;
	printf("\nIngrese operando: ");
	fflush(stdin);
	scanf("%d", &numero);
	return numero;
}
