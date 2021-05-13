/*
 * Recaudacion.c
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
int getDescripcionRecaudacion(eTipo aTipo[], int cantidadTipo, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadTipo; i++)
	{
		if(aTipo[i].tipo==buscar && aTipo[i].isEmpty==0)
		{
			strcpy(descripcion, aTipo[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}
int altaRecaudacion(eRecaudacion aArray[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, int* contadorId)
{
	int retorno = -1;
	eRecaudacion aAuxiliar;
	int posicion;
	int auxI;
	char descripcion[20];

	if(aArray!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0)
	{
		posicion=buscaLibreRecaudacion(aArray, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if(buscaContribuyenteById(aContribuyente, cantidadContribuyente, &auxI)!=-1)
			{
				if((utn_getNumero(&aAuxiliar.tipo, "Ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS", "Error,ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS",1,3,2)==0)&&
				(utn_getNumero(&aAuxiliar.mes, "Ingrese MES", "Error,ingrese MES del 1 al 12",1,12,2)==0)&&
				(utn_getNumeroFlotante(&aAuxiliar.importe, "Ingrese importe","Error, ingrese de 100 a 1000", 100, 1000, 2)==0))
				{
					aAuxiliar.idContribuyente=auxI;
					aAuxiliar.idRecaudacion=0;
					printf("Estos son los datos, desea continuar:");
					if(aAuxiliar.tipo==1)
					{
						strcpy(descripcion,"ARBA");
					}
					if(aAuxiliar.tipo==2)
					{
						strcpy(descripcion,"IIBB");
					}
					if(aAuxiliar.tipo==3)
					{
						strcpy(descripcion,"GANANCIAS");
					}
					imprimir1Recaudacion(aAuxiliar, descripcion);
					if(utn_getCaracterSN()==0)
					{
					   (*contadorId)++;
					   aAuxiliar.idRecaudacion=*contadorId;
					   aAuxiliar.isEmpty=0;
					   aArray[posicion]=aAuxiliar;
					   imprimir1Recaudacion(aAuxiliar, descripcion);
					   retorno=0;
					}
				}
			}
		}
	}
		return retorno;
}
void imprimir1Recaudacion(eRecaudacion aRecaudacion, char* descripcion)
{
	printf("\n %-5d %-5d %-10s %-5%d %-5.2f %-5d ", aRecaudacion.idRecaudacion, aRecaudacion.tipo,
			descripcion,aRecaudacion.mes, aRecaudacion.importe, aRecaudacion.idContribuyente);
}
int imprimirRecaudacion(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo)
{
	int i;
	int retorno = -1;
	char descripcion[20];
	//CABECERA
	puts("\n\t> LISTADO Recaudacion");
	printf("%5s %10s %10s %8s %12s\n", "ID","TIPO","DESCRIPCION","MES","IMPORTE","ID Contribuyente");
	if (array != NULL && cantidadDeArray> 0 && aTipo!=NULL && cantidadTipo>0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				getDescripcionRecaudacion(aTipo, cantidadTipo, array[i].tipo, descripcion);
				imprimir1Recaudacion(array[i], descripcion);
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
int buscaRecaudacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo)
{
	int retorno=-1;
	int auxI;
	int i;
	int j;
	char descripcion[30];
	char aCUIT[14];
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0 && aTipo!=NULL && cantidadTipo>0)
	{
		if((auxI=buscaCUIT(aAuxiliar, cantidadDeArray,aCUIT))>0)
		{
			puts("\n\t> LISTADO Recaudacion");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID Recaudacion");
			for(i=0; i<cantidadContribuyente; i++)
			{
				if(aAuxiliar[auxI].idContribuyente==aContribuyente[i].idContribuyente && aContribuyente[i].isEmpty==0)
				{
					getDescripcionContribuyente(aTipo, cantidadTipo, aContribuyente[i].idContribuyente, descripcion);
					imprimir1Recaudacion(aAuxiliar[auxI]);
					imprimir1Contribuyente(aContribuyente[i], descripcion);
					retorno=0;
				}
			}
		}
		if(auxI==0)
		{
			puts("\n\t> LISTADO Recaudacion");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID Recaudacion");
			for(j=0; j<cantidadDeArray; j++)
			{
				for(i=0; i<cantidadContribuyente; i++)
				{
					if((stricmp(aAuxiliar[j].cuil, aCUIT)==0 && aAuxiliar[j].isEmpty==0)&&
					(aAuxiliar[j].idContribuyente==aContribuyente[i].idContribuyente && aContribuyente[i].isEmpty==0))
					{
						getDescripcionContribuyente(aTipo, cantidadTipo, aContribuyente[i].idContribuyente, descripcion);
						imprimir1Recaudacion(aAuxiliar[j]);
						imprimir1Contribuyente(aContribuyente[i], descripcion);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}
int buscaRecaudacionByIdContribuyente(eRecaudacion aAuxiliar[], int cantidadDeArray, int* aID)
{
	int retorno = -1;
	int i;
	int auxInt;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID de Contribuyente");
		scanf("%d", &auxInt);
		*aID=auxInt;
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idContribuyente==auxInt && aAuxiliar[i].isEmpty==0)
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

/*int ordenarRecaudacion(eRecaudacion array[], int cantidadDeArray, int criterio)
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
int modifica1Recaudacion(eRecaudacion aAuxiliar[], int posicion)
{
	int retorno = -1;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Recaudacion(aAuxiliar[posicion]);
		printf("\n¿Desea modificar esta contratacion?");
		if(utn_getCaracterSN()==0)
		{
			utn_getNumero(&aAuxiliar[posicion].dias, "Ingrese cantidad de dias","Error, ingrese entre 1 y 365", 1, 365, 1);
			printf("Exito, los nuevos datos son: ");
			imprimir1Recaudacion(aAuxiliar[posicion]);
			retorno = 0;
		}
	}
	return retorno;
}
int bajaRecaudacion(eRecaudacion aAuxiliar[], int posicion)
{
	int retorno = -1;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Recaudacion(aAuxiliar[posicion]);
		printf("\n¿Desea borrar esta contratacion?");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

int bajaRecaudacionxContribuyente(eRecaudacion array[], int cantidadDeArray,int ID)
{
	int retorno = -1;
	int i;
	if(array!=NULL && cantidadDeArray>0)
		{
			for(i=0; i<cantidadDeArray; i++)
			{
				if(array[i].idContribuyente==ID)
				{
					array[i].isEmpty=1;
				}
			}
		}
	return retorno;
}
int facturacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente)
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
				for(j=0; j<cantidadContribuyente; j++)
				{
					if(aAuxiliar[i].idContribuyente==aContribuyente[j].idContribuyente)
					{
						resultado=aAuxiliar[i].dias*aContribuyente[j].precio;
						printf("El precio a pagar por la contratacion N° %d es %.2f", aAuxiliar[i].idRecaudacion, resultado);
					}
				}
			}
		}
	}
	return retorno;
}
int listarClientesxCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente)
{
	int retorno=-1;
	int i;
	eRecaudacion auxPub;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0)
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
						informes_ListaDeCliente(aAuxiliar, cantidadDeArray, aContribuyente, cantidadContribuyente, aAuxiliar[i].cuil);
					}
				}
			}
		}
	}
	return retorno;
}
int listarClientesxCUIT1(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente)
{
	int retorno=-1;
	int i;
	eRecaudacion auxPub;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0)
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
						informes_ClienteMasAltoFacturar(aAuxiliar, cantidadDeArray, aContribuyente, cantidadContribuyente, aAuxiliar[i].cuil);
					}
				}
			}
		}
	}
	return retorno;
}
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
					imprimir1Employee(array[i]);
				}
			}
		}
	}
	return retorno;
}*/
