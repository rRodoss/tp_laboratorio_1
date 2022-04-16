/*
 * funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Juan
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

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


#endif /* FUNCIONES_H_ */
