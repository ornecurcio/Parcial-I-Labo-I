/*
 * Publicidad.c
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"
#include "UTN.h"

int inicializarRecaudacion(eRecaudacion pArray[], int cantidadDeArray)
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
int buscaLibreRecaudacion(eRecaudacion pArray[], int cantidadDeArray)
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
int altaPublicidad(eRecaudacion aArray[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla, int* contadorId)
{
	int retorno = -1;
	eRecaudacion aAuxiliar;
	int posicion;
	int auxI;
	if(aArray!=NULL && cantidadDeArray>0 && aPantalla!=NULL && cantidadPantalla>0)
	{
		posicion=buscaLibreRecaudacion(aArray, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if(buscaPantallaById(aPantalla, cantidadPantalla, &auxI)!=-1)
			{
				if((utn_getCUIT(aAuxiliar.cuil, "Ingrese CUIT", "Error,ingrese CUIT", 2)==0)&&
				(utn_getString(aAuxiliar.archivo, "Ingrese Nombre", "Error, ingrese Nombre", 2)==0)&&
				(utn_getNumero(&aAuxiliar.dias, "Ingrese dias de contratacion","Error, ingrese de 1 a 365", 1, 365, 2)==0))
				{
					aAuxiliar.idPantalla=auxI;
					aAuxiliar.idPublicidad=0;
					printf("Estos son los datos, desea continuar:");
					imprimir1Publicidad(aAuxiliar);
					if(utn_getCaracterSN()==0)
					{
					   (*contadorId)++;
					   aAuxiliar.idPublicidad=*contadorId;
					   aAuxiliar.isEmpty=0;
					   aArray[posicion]=aAuxiliar;
					   retorno=0;
					}
				}
			}
		}
	}
		return retorno;
}
void imprimir1Publicidad(eRecaudacion aPublicidad)
{
	printf("\n %-5d  %-10s %-10s %-5d %-5d ", aPublicidad.idPublicidad, aPublicidad.archivo, aPublicidad.cuil, aPublicidad.dias, aPublicidad.idPublicidad);
}
int imprimirPublicidad(eRecaudacion array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;
	//CABECERA
	puts("\n\t> LISTADO PUBLICIDAD");
	printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID PUBLICIDAD");
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
				imprimir1Publicidad(array[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, char* aCUIT)
{
	int retorno = -1;
	int i;
	int contador=0;
	//char aCUIT[14];

	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		utn_getCUIT(aCUIT, "Ingrese CUIT", "Error, ingrese CUIT",2);

		for(i=0; i<cantidadDeArray; i++)
		{
			if((stricmp(aAuxiliar[i].cuil, aCUIT)==0) && aAuxiliar[i].isEmpty==0)
			{
				contador++;
				if(contador==1)
				{
					retorno = i;
				}
				else
				{
					retorno = 0;
				}
			}
			else
			{
				printf("El numero de CUIT %s no existe", aCUIT);
				break;
			}
		}
	}
	return retorno;
}
int buscaPublicidadByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla, eTipo aTipo[], int cantidadTipo)
{
	int retorno=-1;
	int auxI;
	int i;
	int j;
	char descripcion[30];
	char aCUIT[14];
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aPantalla!=NULL && cantidadPantalla>0 && aTipo!=NULL && cantidadTipo>0)
	{
		if((auxI=buscaCUIT(aAuxiliar, cantidadDeArray,aCUIT))>0)
		{
			puts("\n\t> LISTADO PUBLICIDAD");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID PUBLICIDAD");
			for(i=0; i<cantidadPantalla; i++)
			{
				if(aAuxiliar[auxI].idPantalla==aPantalla[i].idContribuyente && aPantalla[i].isEmpty==0)
				{
					getDescripcionPantalla(aTipo, cantidadTipo, aPantalla[i].idContribuyente, descripcion);
					imprimir1Publicidad(aAuxiliar[auxI]);
					imprimir1Pantalla(aPantalla[i], descripcion);
					retorno=0;
				}
			}
		}
		if(auxI==0)
		{
			puts("\n\t> LISTADO PUBLICIDAD");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID PUBLICIDAD");
			for(j=0; j<cantidadDeArray; j++)
			{
				for(i=0; i<cantidadPantalla; i++)
				{
					if((stricmp(aAuxiliar[j].cuil, aCUIT)==0 && aAuxiliar[j].isEmpty==0)&&
					(aAuxiliar[j].idPantalla==aPantalla[i].idContribuyente && aPantalla[i].isEmpty==0))
					{
						getDescripcionPantalla(aTipo, cantidadTipo, aPantalla[i].idContribuyente, descripcion);
						imprimir1Publicidad(aAuxiliar[j]);
						imprimir1Pantalla(aPantalla[i], descripcion);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}
int buscaPublicidadByIdPantalla(eRecaudacion aAuxiliar[], int cantidadDeArray, int* aID)
{
	int retorno = -1;
	int i;
	int auxInt;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID de pantalla");
		scanf("%d", &auxInt);
		*aID=auxInt;
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idPantalla==auxInt && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", auxInt);
				break;
			}
		}
	}
	return retorno;
}

/*int ordenarPublicidad(eRecaudacion array[], int cantidadDeArray, int criterio)
{
		int flagDesordenado = -1;
		int i;
		ePantalla aux;
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
int modifica1Publicidad(eRecaudacion aAuxiliar[], int posicion)
{
	int retorno = -1;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Publicidad(aAuxiliar[posicion]);
		printf("\n¿Desea modificar esta contratacion?");
		if(utn_getCaracterSN()==0)
		{
			utn_getNumero(&aAuxiliar[posicion].dias, "Ingrese cantidad de dias","Error, ingrese entre 1 y 365", 1, 365, 1);
			printf("Exito, los nuevos datos son: ");
			imprimir1Publicidad(aAuxiliar[posicion]);
			retorno = 0;
		}
	}
	return retorno;
}
int bajaPublicidad(eRecaudacion aAuxiliar[], int posicion)
{
	int retorno = -1;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Publicidad(aAuxiliar[posicion]);
		printf("\n¿Desea borrar esta contratacion?");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

int bajaPublicidadxPantalla(eRecaudacion array[], int cantidadDeArray,int ID)
{
	int retorno = -1;
	int i;
	if(array!=NULL && cantidadDeArray>0)
		{
			for(i=0; i<cantidadDeArray; i++)
			{
				if(array[i].idPantalla==ID)
				{
					array[i].isEmpty=1;
				}
			}
		}
	return retorno;
}
int facturacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla)
{
	int retorno=-1;
	char aCUIT[14];
	int i;
	int j;
	float resultado;
	if(aAuxiliar!=NULL && (cantidadDeArray>0) && (buscaCUIT(aAuxiliar, cantidadDeArray, aCUIT)!=-1))
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(stricmp(aAuxiliar[i].cuil, aCUIT)==0 && aAuxiliar[i].isEmpty==0)
			{
				for(j=0; j<cantidadPantalla; j++)
				{
					if(aAuxiliar[i].idPantalla==aPantalla[j].idContribuyente)
					{
						resultado=aAuxiliar[i].dias*aPantalla[j].precio;
						printf("El precio a pagar por la contratacion N° %d es %.2f", aAuxiliar[i].idPublicidad, resultado);
					}
				}
			}
		}
	}
	return retorno;
}
int listarClientesxCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla)
{
	int retorno=-1;
	int i;
	eRecaudacion auxPub;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aPantalla!=NULL && cantidadPantalla>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty==1)
			{
				continue;
			}
			else
			{
				if(stricmp(aAuxiliar[i].cuil, aAuxiliar[i+1].cuil)>0)
				{
					auxPub=aAuxiliar[i];
					aAuxiliar[i]=aAuxiliar[i+1];
					aAuxiliar[i+1]=auxPub;
				}
				else
				{
					if(stricmp(aAuxiliar[i].cuil, aAuxiliar[i+1].cuil)==0)
					{
						informes_ListaDeCliente(aAuxiliar, cantidadDeArray, aPantalla, cantidadPantalla, aAuxiliar[i].cuil);
					}
				}
			}
		}
	}
	return retorno;
}
int listarClientesxCUIT1(eRecaudacion aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla)
{
	int retorno=-1;
	int i;
	eRecaudacion auxPub;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aPantalla!=NULL && cantidadPantalla>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty==1)
			{
				continue;
			}
			else
			{
				if(stricmp(aAuxiliar[i].cuil, aAuxiliar[i+1].cuil)>0)
				{
					auxPub=aAuxiliar[i];
					aAuxiliar[i]=aAuxiliar[i+1];
					aAuxiliar[i+1]=auxPub;
				}
				else
				{
					if(stricmp(aAuxiliar[i].cuil, aAuxiliar[i+1].cuil)==0)
					{
						informes_ClienteMasAltoFacturar(aAuxiliar, cantidadDeArray, aPantalla, cantidadPantalla, aAuxiliar[i].cuil);
					}
				}
			}
		}
	}
	return retorno;
}
/*int ePantallaPromSalario(float* pPromedioResultado, ePantalla array[], int cantidadDeArray)
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
/*int ePantallasListaSalario(ePantalla array[], int cantidadDeArray, float salary)
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
					imprimir1Employee(array[i]);
				}
			}
		}
	}
	return retorno;
}*/
