/*
 ============================================================================
 Name        : ModeloParcialPubli.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "Recaudacion.h"
#include "Contribuyente.h"

#define QTY_CONTRIBUYENTE 50
#define QTY_RECAUDACION 50
#define QTY_TIPO 3

int main(void) {
	setbuf(stdout, NULL);

		eTipo vecTipo[QTY_TIPO]={
				{1, "ARBA", 0},
				{2, "IIBB", 0},
				{3, "GANACIAS", 0},
		};

		eContribuyente vecContribuyente[QTY_CONTRIBUYENTE];
		eRecaudacion vecRecaudacion[QTY_RECAUDACION];
		int contadorContribuyente=1000;
		int contadorRecaudacion=100;
		int auxInt;
		int posicion;
		int respuestaMenuPrincipal;
		//float auxFloat;

		inicializarContribuyente(vecContribuyente, QTY_CONTRIBUYENTE);
		inicializarRecaudacion(vecRecaudacion, QTY_RECAUDACION);
	do{
		if(utn_getNumero(&respuestaMenuPrincipal, "1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja de contribuyente\n"
				"4.Recaudación\n5.Refinanciar Recaudación\n6.Saldar Recaudación\n"
				"7.Imprimir Contribuyentes\n8.Imprimir Recaudación",
				"ERROR INGRESE OPCION VALIDA:"
				"1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja de contribuyente"
				"\n4.Recaudación\n5.Refinanciar Recaudación\n6.Saldar Recaudación"
				"\n7.Imprimir Contribuyentes\n8.Imprimir Recaudación\n", 1, 8, 2)==0)
		{
			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA CONTRIBUYENTE
					if(altacontribuyente(vecContribuyente, QTY_CONTRIBUYENTE, &contadorContribuyente)==0)
					{
						printf("Carga exitosa\n");
					}
					break;
				case 2://MODIFICAR CONTRIBUYENTE
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{
						modifica1contribuyente(vecContribuyente, buscaContribuyenteById(vecContribuyente, QTY_CONTRIBUYENTE,&auxInt));
					}
					break;
				case 3://BAJA CONTRIBUYENTE
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{
						bajacontribuyente(vecContribuyente, buscaContribuyenteById(vecContribuyente, QTY_CONTRIBUYENTE, &auxInt));
						bajaRecaudacionxContribuyente(vecRecaudacion, QTY_RECAUDACION, auxInt);
					}
					break;
				case 4: // ALTA RECAUDACION
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{
						imprimircontribuyentes(vecContribuyente, QTY_CONTRIBUYENTE);
						altaRecaudacion(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE, &contadorRecaudacion);
					}
					break;
				case 5://REFINANCIAR RECAUDACION
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{
						auxInt=buscaIDRecaudacionRetIDCon(vecRecaudacion, QTY_RECAUDACION, contadorRecaudacion, &posicion);
						imprimir1Contribuyente(vecContribuyente[buscaContribuyenteXIdParametro(vecContribuyente, QTY_CONTRIBUYENTE, auxInt)]);
						estadoRecaudacionRefinanciar(vecRecaudacion, posicion, vecTipo, QTY_TIPO);
					}
					break;
				case 6: // CANCELA PUBLICDAD
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{
						auxInt=buscaIDRecaudacionRetIDCon(vecRecaudacion, QTY_RECAUDACION, contadorRecaudacion, &posicion);
						imprimir1Contribuyente(vecContribuyente[buscaContribuyenteXIdParametro(vecContribuyente, QTY_CONTRIBUYENTE, auxInt)]);
						estadoRecaudacionSaldar(vecRecaudacion, posicion, vecTipo, QTY_TIPO);
					}
					break;
				case 7: // IMprimeContribuyente
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{
						facturacionByCUIT(vecClientes, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE);
					}
					break;
				case 8: // imprime recaudacion
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una contribuyente");
					}
					else
					{

					}
					break;
			}//fin switch
		}//fin if menu
	}while(respuestaMenuPrincipal!=8);

return EXIT_SUCCESS;
}
