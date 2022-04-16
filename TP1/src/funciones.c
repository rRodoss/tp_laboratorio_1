/*
 * funciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>

int myGets(char* cadena, int longitud);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
static int getInt(int* pResultado);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
static int esNumerica(char* cadena, int limite);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int ingresarKms(float* kilometros);
int precioVuelos(float* precioAerolineas, float* precioLatam);
int calcularCostos(float *debitLat, float* debitAero, float* creditLat, float* creditAero, float* btcLat, float* btcAero, float* difffLatAero, float* priceXKmLat, float* priceXKmAero, float* precioAero, float* precioLat, float* kilometros);
float diferenciaPrecio(float* x, float* y);
void mostrarResultados(float* kilometros, float* debitLat, float* creditLat, float* btcLat, float* priceXKmLat, float* debitAero, float* creditAero, float* btcAero, float* priceXKmAero, float* diffLatAero, float* precioAero, float* precioLat);


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un maximo de 'longitud - 1' de caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de la cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un char al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el numero minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */


int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%c", &buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;
}

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if( pResultado != NULL &&
			myGets(bufferString, sizeof(bufferString)) == 0 &&
			esNumerica(bufferString, sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}

	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el numero minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s", mensaje);
		if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 si la cadena es numerica, 0 si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0' ;i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}

	}

	return retorno;
}

/**
 * \brief Solicita un float al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el numero minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
			printf("%s", mensaje);
			scanf ("%f", &bufferFloat);
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0 );
	}
	return retorno;
}

int ingresarKms(float* kilometros)
{
	int resultado;
	resultado = utn_getNumeroFlotante(kilometros, "Por favor, ingrese los Kilómetros:\n", "Por favor, intente de nuevo\n", 0, 50000, 3);
	if(resultado == 0)
	{
		printf("\n KMs Ingresados: %.2f\n", *kilometros);
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * \brief Pide el precio de los vuelos
 * \return Retorna el resultado
 *
 */

int precioVuelos(float* precioAerolineas, float* precioLatam)
{
	int resultadoUno;
	int resultadoDos;

	resultadoUno = utn_getNumeroFlotante(precioAerolineas, "Ingrese el precio del vuelo Aerolineas:\n", "Por favor, intente de nuevo\n", 1, 10000000, 3);
	fflush(stdin);
	resultadoDos = utn_getNumeroFlotante(precioLatam, "Ingrese el precio del vuelo Latam:\n", "Por favor, intente de nuevo\n", 1, 10000000, 3);

	if(resultadoUno == 0 && resultadoDos == 0)
	{
		printf("El precio del vuelo Aerolineas es %.2f y Latam es %.2f \n", *precioAerolineas, *precioLatam);
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * \brief Calcula los costos de cada medio de pago y cada aerolinea
 * \return Retorna
 *
 */

int calcularCostos(float *debitLat, float* debitAero, float* creditLat, float* creditAero, float* btcLat, float* btcAero, float* diffLatAero, float* priceXKmLat, float* priceXKmAero, float* precioAero, float* precioLat, float* kilometros)
{
	*debitAero = *precioAero * 0.9;
	*debitLat = *precioLat * 0.9;
	*creditAero = *precioAero * 1.25;
	*creditLat = *precioLat * 1.25;
	*btcAero = 4606954 / *precioAero;
	*btcLat = 4606954 / *precioLat;
	*priceXKmAero = *kilometros * *precioAero;
	*priceXKmLat = *kilometros * *precioLat;

	*diffLatAero = diferenciaPrecio(precioAero, precioLat);
	return 1;
}


/**
 * \brief Calcula la diferencia entre dos numeros
 * \return Retorna la diferencia numerica
 *
 */
float diferenciaPrecio(float* x, float* y)
{
	float diff;
	if (x>y) {
	     diff = (x-y);
	} else if (y>x) {
	     diff = (y-x);
	} else if (x==y) {
	    diff = 0;
	}
	return diff;
}

/**
 * \brief Muestra los resultados de calcularCostos
 * \return void
 *
 */
void mostrarResultados(float* kilometros, float* debitLat, float* creditLat, float* btcLat, float* priceXKmLat, float* debitAero, float* creditAero, float* btcAero, float* priceXKmAero, float* diffLatAero, float* precioAero, float* precioLat)
{
	printf("KMs Ingresados: %2.f\n", *kilometros);

	printf("Precio Aerolineas: $ %2.f\na) Precio con tarjeta de debito: $ %2.f\nb) Precio con tarjeta de credito: $ %2.f\nc) Precio pagando con Bitcoin: BTC %2.f\nd) Mostrar precio unitario: $ %2.f\n", *precioAero, *debitAero, *creditAero, *btcAero, *priceXKmAero);

	printf("Precio Latam: $ %2.f\na) Precio con tarjeta de debito: $ %2.f\nb) Precio con tarjeta de credito: $ %2.f\nc) Precio pagando con Bitcoin: BTC %2.f\nd) Mostrar precio unitario: $ %2.f\n", *precioLat, *debitLat, *creditLat, *btcLat, *priceXKmLat);
}
