/*
 * Informe.c
 *
 *  Created on: 13 may. 2021
 *      Author: orne_
 */
#include "Recaudacion.h"
#include "Recaudacion.c"

int informes_ListaDeCliente(ePublicidad aAuxiliar[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla, char* aCUIT)
{
	int retorno=-1;
	int i, j;
	float resultado;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aPantalla!=NULL && cantidadPantalla>0)
	{
		printf("CLIENTE--------CONTRATACION------PRECIO");
		for(i=0; i<cantidadDeArray; i++)
		{
			if(strcmp(aAuxiliar[i].cuil, aCUIT)==0)
			{
				for(j=0; j<cantidadPantalla; j++)
				{
					if(aAuxiliar[i].idPantalla==aPantalla[j].idPantalla)
					{
						resultado=aAuxiliar[i].dias*aPantalla[j].precio;
						printf("\n%-15s    %-8d      %-.2f", aCUIT, aAuxiliar[i].idPublicidad, resultado);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}

