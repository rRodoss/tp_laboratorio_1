/*
 ============================================================================
 Name        : TP.c
 Author      : Juan Rodriguez Peluffo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	//MENU
	int opcion;
	int respuesta;

	//VALIDACIONES
	int retornoUno;
	int retornoDos;
	int retornoTres;
	int retornoCinco;

	//DATOS A INGRESAR
	float* kms;
	float* precioUno;
	float* precioDos;
	float* debitoLatam;
	float* debitoAerolineas;
	float* creditoLatam;
	float* creditoAerolineas;
	float* bitcoinLatam;
	float* bitcoinAerolineas;
	float* precioXKmLatam;
	float* precioXKmAerolineas;
	float* diferenciasLatAero;


	do
	{
		respuesta = utn_getNumero(&opcion, "\nSeleccione una opcion\n1- Ingresar Kilómetros\n2- Ingresar Precio de Vuelos\n3- Calcular todos los costos\n4- Informar Resultados\n5- Carga Forzada de datos\n6- Salir\n", "No es una opcion válida\n", 1, 6, 2);
		if(!respuesta)
		{
			switch(opcion)
			{
			case 1:
				retornoUno = ingresarKms(&kms);
				break;
			case 2:
				if(retornoUno == 1)
				{
					retornoDos = precioVuelos(&precioUno, &precioDos);
				}
				else
				{
					printf("Error, no se ingresaron los kilómetros\n");
				}
				break;
			case 3:
				if(retornoDos == 1)
				{
					retornoTres = calcularCostos(&debitoLatam, &debitoAerolineas, &creditoLatam, &creditoAerolineas, &bitcoinLatam, &bitcoinAerolineas, &diferenciasLatAero, &precioXKmLatam, &precioXKmAerolineas, &precioUno, &precioDos, &kms);
					if(retornoTres == 1)
					{
						printf("\nCalculados\n");
					}
				}
				else
				{
					printf("Error, no se ingresaron los precios de los vuelos\n");
				}
				break;
			case 4:
				if(retornoTres == 1 || retornoCinco == 1)
				{
					mostrarResultados(&kms, &debitoLatam, &creditoLatam, &bitcoinLatam, &precioXKmLatam, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &precioXKmAerolineas, &diferenciasLatAero, &precioUno, &precioDos);
				}
				else
				{
					printf("Error, no se calcularon los costos\n");
				}
				break;
			case 5: ;
			{
					float precio1 = 162965;
					float precio2 = 159339;
					float kilometers = 7090;
					printf("%2.f, %2.f, %2.f", precio1, precio2, kilometers);
					calcularCostos(&debitoLatam, &debitoAerolineas, &creditoLatam, &creditoAerolineas, &bitcoinLatam, &bitcoinAerolineas, &diferenciasLatAero, &precioXKmLatam, &precioXKmAerolineas, &precio1, &precio2, &kilometers);
					mostrarResultados(&kilometers, &debitoLatam, &creditoLatam, &bitcoinLatam, &precioXKmLatam, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &precioXKmAerolineas, &diferenciasLatAero, &precio1, &precio2);
			}
				break;
			case 6:
				printf("Terminado");
				break;
			}
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}
