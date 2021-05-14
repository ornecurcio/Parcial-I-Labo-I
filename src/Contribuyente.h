/*
 * Contribuyente.h
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */

#ifndef Contribuyente_H_
#define Contribuyente_H_


typedef struct
{
	int idContribuyente;
	char name[30];
	char apellido[30];
	char cuit[14];
	int isEmpty;
}eContribuyente;

/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarContribuyente(eContribuyente pArray[], int cantidadDeArray);
/** \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibreContribuyente(eContribuyente pArray[], int cantidadDeArray);
/** \brief alta un empleado, llama a otras funciones que valida los datos de cada campo a cargar
* \param aEmployee array donde se cargan los datos
* \param cantidadDeArray int, recorrer array
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int altaContribuyente(eContribuyente aEmployee[], int cantidadDeArray, int* contadorId);
/** \brief imprime un empleado
* \param aEmpleado, recibe por valor la estructura de un empleado
*/
void imprimir1Contribuyente(eContribuyente aContribuyente);

int imprimirContribuyentes(eContribuyente array[], int cantidadDeArray);

int buscaContribuyenteXIdParametro(eContribuyente aAuxiliar[], int cantidadDeArray, int aID);

int buscaContribuyenteById(eContribuyente aAuxiliar[], int cantidadDeArray, int* aID);

int bajaContribuyente(eContribuyente aAuxiliar[], int posicion);

int ordenarContribuyente(eContribuyente array[], int cantidadDeArray, int criterio);

int modifica1Contribuyente(eContribuyente aAuxiliar[], int posicion);

#endif /* Contribuyente_H_ */
