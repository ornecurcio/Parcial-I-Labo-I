/*
 * Recaudacion.h
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#include "Contribuyente.h"

#define SALDADO 0
#define REFINANCIAR 1
#define ALTA 2

typedef struct
{
	int tipo;
	char descripcion[50];
	int isEmpty;
}eTipo;

typedef struct
{
	int idRecaudacion;
	int idContribuyente;
	int tipo;
	int mes;
	float importe;
	int estado;
	int isEmpty;
}eRecaudacion;

/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarRecaudacion(eRecaudacion pArray[], int cantidadDeArray);
/** \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibreRecaudacion(eRecaudacion pArray[], int cantidadDeArray);
/** \brief alta un recaudacion, llama a otras funciones que valida los datos de cada campo a cargar
* \param aEmployee array donde se cargan los datos
* \param cantidadDeArray int, recorrer array
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int getDescripcionRecaudacion(eTipo aTipo[], int cantidadDeArray, int buscar, char* descripcion);

int altaRecaudacion(eRecaudacion aArray[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla, int* contadorId);
/** \brief imprime un recaudacion
* \param arecaudacion, recibe por valor la estructura de un recaudacion
*/
void imprimir1Recaudacion(eRecaudacion aRecaudacion);

int imprimirRecaudacion(eRecaudacion array[], int cantidadDeArray);

int buscaIDRecaudacionRetIDCon(eRecaudacion aAuxiliar[], int cantidadDeArray, int contadorRecauda);

int buscaRecaudacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla, eTipo aTipo[], int cantidadTipo);

int buscaRecaudacionByIdPantalla(eRecaudacion aAuxiliar[], int cantidadDeArray, int* aID);

//int ordenarRecaudacion(eRecaudacion array[], int cantidadDeArray, int criterio);

int modifica1Recaudacion(eRecaudacion aAuxiliar[], int posicion);

int bajaRecaudacion(eRecaudacion aAuxiliar[], int posicion);

int estadoRecaudacionRefinanciar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo);

int estadoRecaudacionSaldar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo);

int bajaRecaudacionxPantalla(eRecaudacion array[], int cantidadDeArray,int ID);

int facturacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla);

int listarClientesxCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla);

int listarClientesxCUIT1(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla);
#endif /* CONTRIBUYENTE_H_ */
