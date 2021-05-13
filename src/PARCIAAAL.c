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

#define QTY_CONTRIBUYENTE 3
#define QTY_RECAUDACION 2
#define QTY_TIPO 2
int main(void) {
	setbuf(stdout, NULL);

		eTipo vecTipo[QTY_TIPO]={
				{1, "LCD", 0},
				{2, "LED", 0},
		};
		eContribuyente vecContribuyente[QTY_CONTRIBUYENTE];
		eRecaudacion vecRecaudacion[QTY_RECAUDACION];
		int contadorContribuyente=1000;
		int contadorRecaudacion=0;
		int submenu;
		int auxInt;
		int respuestaMenuPrincipal;
		//float auxFloat;

		inicializarContribuyente(vecContribuyente, QTY_CONTRIBUYENTE);
		inicializarRecaudacion(vecRecaudacion, QTY_RECAUDACION);
	do{
		if(utn_getNumero(&respuestaMenuPrincipal, "1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja de contribuyente\n"
				"4.Recaudaci�n\n5.Refinanciar Recaudaci�n\n6.Saldar Recaudaci�n\n"
				"7.Imprimir Contribuyentes\n8.Imprimir Recaudaci�n",
				"ERROR INGRESE OPCION VALIDA:"
				"1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja de contribuyente"
				"\n4.Recaudaci�n\n5.Refinanciar Recaudaci�n\n6.Saldar Recaudaci�n"
				"\n7.Imprimir Contribuyentes\n8.Imprimir Recaudaci�n\n", 1, 8, 2)==0)
		{
			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA CONTRIBUYENTE
					if(altaPantalla(vecContribuyente, QTY_CONTRIBUYENTE, &contadorContribuyente)==0)
					{
						printf("Carga exitosa\n");
					}
					break;
				case 2://MODIFICAR CONTRIBUYENTE
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						modifica1Pantalla(vecContribuyente, buscaPantallaById(vecContribuyente, QTY_CONTRIBUYENTE,&auxInt), vecTipo, QTY_TIPO);
					}
					break;
				case 3://BAJA CONTRIBUYENTE
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						bajaPantalla(vecContribuyente, buscaPantallaById(vecContribuyente, QTY_CONTRIBUYENTE, &auxInt), vecTipo, QTY_TIPO);
						bajaPublicidadxPantalla(vecRecaudacion, QTY_CONTRIBUYENTE, auxInt);
					}
					break;
				case 4: // ALTA PUBLICIDAD
					if(contadorPantallas==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						imprimirPantallas(vecContribuyente, QTY_CONTRIBUYENTE, vecTipo, QTY_TIPO);
						altaPublicidad(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE, &contadorRecaudacion);
					}
					break;
				case 5://MODIFICA PUBLICIDAD
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						buscaPublicidadByCUIT(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE, vecTipo, QTY_TIPO);
						buscaPublicidadByIdPantalla(vecRecaudacion, QTY_RECAUDACION, &auxInt);
						modifica1Publicidad(vecRecaudacion, auxInt);
					}
					break;
				case 6: // CANCELA PUBLICDAD
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						buscaPublicidadByCUIT(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE, vecTipo, QTY_TIPO);
						buscaPublicidadByIdPantalla(vecRecaudacion, QTY_RECAUDACION, &auxInt);
						bajaPublicidad(vecRecaudacion, auxInt);
					}
					break;
				case 7: // FACTURACION
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						facturacionByCUIT(vecClientes, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE);
					}
					break;
				case 8: // IMPRIME PUBLICIDAD
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						imprimirPublicidad(vecRecaudacion, QTY_RECAUDACION);
					}
					break;
				case 9: //IMPRIME PANTALLAS
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						imprimirPantallas(vecContribuyente, QTY_CONTRIBUYENTE, vecTipo, QTY_TIPO);
					}
					break;
				case 10: //INFORMES
					if(contadorContribuyente==0)
					{
						printf("Error, primero debe ingresar una pantalla");
					}
					else
					{
						do{
						utn_getNumero(&submenu, "\n1.Lista de Clientes con cantidad de contrataciones e importe a pagar por cada una"
								"\n2.Cliente con importe mas alto a facturar\n3.Salir", "Error, opcion incorrecta", 1, 3, 2);
							switch(submenu)
							{
							case 1:
								listarClientesxCUIT(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE);
								break;
							case 2:
								listarClientesxCUIT1(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE);
								break;
							}
						}while(submenu!=3);
					}
					break;
			}
		}
	}while(respuestaMenuPrincipal!=5);

		return EXIT_SUCCESS;
}