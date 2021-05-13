/*
 * Contribuyente.c
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */
#include "Contribuyente.h"
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
int inicializarContribuyente(eContribuyente pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int buscaLibreContribuyente(eContribuyente pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(pArray[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int altaContribuyente(eContribuyente aContribuyente[], int cantidadDeArray, int* contadorId)
{
	int retorno = -1;
	eContribuyente aAuxiliar;
	int posicion;
	char descripcion[30];
	if(aContribuyente!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscaLibreContribuyente(aContribuyente, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getNombre(aAuxiliar.name, "Ingrese nombre de Contribuyente", "Error muy largo", 2, TAM)==0)&&
			(utn_getNombre(aAuxiliar.apellido, "Ingrese apellido de Contribuyente", "Error muy largo", 2, TAM)==0)&&
			(utn_getCUIT(aAuxiliar.cuit, "Ingrese cuit de la forma XX-XXXXXXXX-X", "Error, reingrese", 2)==0))
			{
				aAuxiliar.idContribuyente=0;

				printf("Estos son los datos, desea continuar:");
				imprimir1Contribuyente(aAuxiliar, descripcion);
				if(utn_getCaracterSN()==0)
				{
				   (*contadorId)++;
				   aAuxiliar.idContribuyente=*contadorId;
				   aAuxiliar.isEmpty=0;
				   aContribuyente[posicion]=aAuxiliar;
				   imprimir1Contribuyente(*aContribuyente[posicion]);
				   retorno=0;
				}
			}
		}
	}
		return retorno;
}
void imprimir1Contribuyente(eContribuyente aContribuyente)
{
	printf("\n %-5d %-15s %-15s %-15s ", aContribuyente.idContribuyente, aContribuyente.apellido, aContribuyente.name,aContribuyente.cuit);
}
int imprimirContribuyentes(eContribuyente array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;
	//CABECERA
	puts("\n\t> LISTADO ContribuyenteS");
	printf("%5s %15s %15s %15s\n", "ID","APELLIDO","NOMBRE","CUIT");
	if (array != NULL && cantidadDeArray> 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				imprimir1Contribuyente(array[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaContribuyenteById(eContribuyente aAuxiliar[], int cantidadDeArray, int* aID)
{
	int retorno = -1;
	int i;
	int auxI;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("\nIngrese ID Contribuyente");
		scanf("%d", &auxI);
		*aID=auxI;
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idContribuyente==auxI && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", auxI);
				break;
			}
		}
	}
	return retorno;
}
int bajaContribuyente(eContribuyente aAuxiliar[], int posicion, eTipo aTipos[], int cantidadTipos)
{
	int retorno = -1;
	char descripcion[20];
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		getDescripcionContribuyente(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Contribuyente(aAuxiliar[posicion], descripcion);
		printf("\nDesea borrar esta Contribuyente");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].isEmpty=1;

			retorno = 0;
		}
	}
	return retorno;
}
int modifica1Contribuyente(eContribuyente aAuxiliar[], int posicion)
{
	int retorno = -1;
	int respuesta;

	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Contribuyente(aAuxiliar[posicion]);
		printf("\n¿Desea modificar esta Contribuyente?");
		if(utn_getCaracterSN()==0)
		{
			printf("\nDesea modificar \n1.Nombre\n2.Apellido\n3.Cuit");
			scanf("%d", &respuesta);
			while(respuesta>3 || respuesta<1)
			{
				printf("\nDesea modificar \n1.Nombre\n2.Apellido\n3.Cuit");
				scanf("%d", &respuesta);
			}
			switch(respuesta)
			{
				case 1:
					utn_getNombre(aAuxiliar[posicion].name, "Ingrese nombre de Contribuyente", "Error muy largo", 2, TAM);
					printf("Exito, los nuevos datos son: ");
					imprimir1Contribuyente(aAuxiliar[posicion]);
					break;
				case 2:
					utn_getNombre(aAuxiliar[posicion].apellido, "Ingrese apellido de Contribuyente", "Error muy largo", 2, TAM);
					printf("Exito, los nuevos datos son: ");
					imprimir1Contribuyente(aAuxiliar[posicion]);
					break;
				case 3:
					utn_getCUIT(aAuxiliar[posicion].cuit, "Ingrese cuit de la forma XX-XXXXXXXX-X", "Error, reingrese", 2);
					printf("Exito, los nuevos datos son: ");
					imprimir1Contribuyente(aAuxiliar[posicion]);
					break;
			}
			retorno = 0;
		}
	}
	return retorno;
}
int getDescripcionContribuyente(eTipo aTipo[], int cantidadDeArray, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadDeArray; i++)
	{
		if(aTipo[i].tipo==buscar && aTipo[i].isEmpty==0)
		{
			strcpy(descripcion, aTipo[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}
/*int ordenarContribuyentes(eContribuyente array[], int cantidadDeArray, int criterio)
{
		int flagDesordenado = -1;
		int i;
		eContribuyente aux;
		int retorno=-1;

		if(array!=NULL && cantidadDeArray>0)
		{
			do {
				flagDesordenado=0;
				for (i = 0; i < cantidadDeArray-1; ++i)
				{
					if(criterio == 0)
					{
							if(strcmp(array[i].lastName,array[i+1].lastName)>0)
							{
								flagDesordenado=1;
								aux=array[i];
								array[i]=array[i+1];
								array[i+1]=aux;
							}
							else
							{
									if(strcmp(array[i].lastName,array[i+1].lastName)==0 && array[i].sector > array[i+1].sector)
									{
										flagDesordenado=1;
										aux=array[i];
										array[i]=array[i+1];
										array[i+1]=aux;
									}
							}
						}
						else
						{
							if(criterio == 1)
							{
								if(strcmp(array[i+1].lastName,array[i].lastName)>0)
								{
									flagDesordenado=1;
									aux=array[i];
									array[i]=array[i+1];
									array[i+1]=aux;
								}
								else
								{
									if(strcmp(array[i].lastName,array[i+1].lastName)==0 && array[i+1].sector > array[i].sector)
									{
										flagDesordenado=1;
										aux=array[i];
										array[i]=array[i+1];
										array[i+1]=aux;
									}
								}
							}
						}
					}
				} while (flagDesordenado==0);
				retorno=0;
		}
		return retorno;
}
*/
/*int eContribuyentePromSalario(float* pPromedioResultado, eContribuyente array[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int acumulador=0;
	int contador=0;

	if(pPromedioResultado != NULL && array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].isEmpty==0)
			{
			acumulador =+ array[i].salary;
			contador++;
			}
		}
		*pPromedioResultado = acumulador/contador;
		printf("El salario promedio es: %.2f", *pPromedioResultado);
		retorno = 0;
	}
	return retorno;
}*/
/*int eContribuyentesListaSalario(eContribuyente array[], int cantidadDeArray, float salary)
{
	int retorno=-1;
	int i;

	if(array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].isEmpty==0)
			{
				if(array[i].salary>=salary)
				{
					imprimir1Contribuyente(array[i]);
				}
			}
		}
	}

	return retorno;
}*/
