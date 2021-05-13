/*
 * numeros.c
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int getInt(int* pResultado);
int esNumerica(char* cadena, int longitud);
int getFloat(float* pResultado);
int esFlotante(char* cadena, int longitud);
int myGets(char* cadena, int longitud);

void getString(char mensaje[], char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
void getChar(char* mensaje, char* rta)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", rta);
}
int utn_getCaracterSN(void)
{
	int retorno = -1;
	char c;

	getChar("Ingrese Si 's' o No 'n'", &c);

	while(c!='s' && c!='n')
	{
		puts("ERROR. OPCION NO VALIDA");
		getChar("Ingrese Si 's' o No 'n'", &c);

	}
		if(c=='s')
		{
			retorno = 0;
		}
	return retorno;
}
//------VALIDACIONES COSAS- dan 1 si TRUE
int esNumerica(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	if(cadena!=NULL)
	{

		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int esFlotante(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	int contadorPunto=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				if(cadena[i]=='.' && contadorPunto==0)
				{
					contadorPunto++;
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}
	return retorno;
}
int esNombre(char* cadena,int longitud)
{
	int retorno = 1;

	if(cadena!=NULL && longitud>0)
	{
		for(int i=0; i<=longitud && cadena[i] != '\0';i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != '.')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int esSoloLetra(char *pResultado)
{
	int retorno = 1;
	int i;

	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		for (i = 0; i<strlen(pResultado); i++)
		{
			if (isalpha(pResultado[i]) == 0)
			{
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = 0;
	}
	return retorno;
}
int esLetraConEspacio(char *pResultado)
{
	int retorno = 1;
	int i;

	if (pResultado!=NULL && strlen(pResultado)>0)
	{
		for(i = 0; i < strlen(pResultado); i++)
		{
			if (isalpha(pResultado[i])==0)
			{
				if (isspace(pResultado[i])==0)
				{
					retorno=0;
					break;
				}
			}
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
int esTelefonoValido(char* cadena)
{
    int retorno=1;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='-' || cadena[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//------GETS COSAS----------
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[5000];
	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado!=NULL)
	{
		if(myGets(bufferString, sizeof(bufferString))==0 && esNumerica(bufferString, sizeof(bufferString))==1)
		{
			*pResultado=atoi(bufferString);
			retorno=0;
		}
	}

	return retorno;
}
int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if(pResultado!=NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer, sizeof(buffer))==1)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}
int getNombre(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[5000];
	if(pResultado!=NULL && longitud>0)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNombre(buffer, sizeof(buffer))!=0 && strnlen(buffer, sizeof(buffer))<=longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno=0;
		}
	}
	return retorno;
}
//------------UTN cosas-----------
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char string[][20], int cantidadArray, int reintentos)
{
	int retorno = -1;
	char bufferChar[40];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferChar);

			if(strlen(bufferChar)<20)
			{
				strcpy(pResultado,bufferChar);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, char string[][20], int cantidadArray, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", &bufferChar);
			if(bufferChar=='f'|| bufferChar=='m' || bufferChar=='o')
			{
				*pResultado=bufferChar;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(myGets(bufferString,40)==0)
			{
				strcpy(aux, bufferString);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud)
{
	char bufferString[1000];
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && longitud > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString, 1000)==0)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos)
{
    int retorno=-1;
    char bufferStr[50];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && min<max && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
            if(myGets(bufferStr, 50)==0 && esTelefonoValido(bufferStr)==1)
            {
                    strcpy(pResultado,bufferStr);
                    retorno=0;
                    break;
            }
            else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
        }
        while(reintentos>=0);
    }
    return retorno;
}
int esCUIT(char* cadena)// es lo que hay
{
    int retorno=1;
    int i;
    int j;
    char buffer[14];
    int contadorDigito;
    int contadorGuion;
    strncpy(buffer,cadena,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-'))
        {
            retorno=0;
            break;
        }
        else
        {
        	if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
        	{
				if(cadena[i]=='-')
				{
					contadorGuion++;
        		}
        		else
        		{
					retorno=0;
					break;
        		}
        	}
        }
    }
	if(contadorDigito==11 && contadorGuion==2 && buffer[2]=='-' && buffer[11]=='-')
	{
		retorno=1;
	}
    return retorno;
}
int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int maxTamanio=14; //con guiones 13 elementos
    int minTamanio=11;  // sin puntos
    int retorno=-1;
    char bufferStr[maxTamanio];
    if(mensaje!=NULL && mensajeError!=NULL && maxTamanio>minTamanio && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
            if((myGets(bufferStr, 14)==0) && (esCUIT(bufferStr)==1))
			{
                strncpy(pResultado,bufferStr,maxTamanio);
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
//-------ARRAY cosas----
void inicializarArrayChar(char pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=' ';
	}
}
int inicializarArrayFlotante(float pArray[], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	   if(pArray!=NULL && cantidadDeArray>0)
	   {
			for(i=0; i<cantidadDeArray; i++)
			{
				pArray[i]=0;
			}
			retorno=0;
	   }
	  return retorno;
}
int imprimirArrayFlotante(float pArray[], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	   if(pArray!=NULL && cantidadDeArray>0)
	   {
			for(i=0; i<cantidadDeArray; i++)
			{
				printf("\nIndice [%d] - Valor %2.f", i, pArray[i]);
			}
			retorno=0;
	   }
	  return retorno;
}
int inicializarArrayCadena(char pArray[][20], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			strcpy(pArray[i],"");
		}
		retorno=0;
	}
	return retorno;
}
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray)
{
	int i;
	int j;
	int aux;
	int retorno = -1;
	if(listaDeArray!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray-1; i++)
		{
			for(j=i+1; j<cantidadDeArray; j++)
			{
				if(listaDeArray[i]>listaDeArray[j])
				{
					aux=listaDeArray[i];
					listaDeArray[i]=listaDeArray[j];
					listaDeArray[j]=aux;
				}

			}
		}
		retorno=0;
	}
	return retorno;
}

void FormaApellidoNombre(char *pNombre, char *pApellido, char *pCompleto)
{
	strcpy(pCompleto, pApellido);
	strcat(pCompleto, ", ");
	strcat(pCompleto, pNombre);
	strlwr(pCompleto);
	if (strlen(pNombre) > 0 && strlen(pApellido) > 0)
	{
		for(int i = 0; i < strlen(pCompleto); i++)
		{
			if (i == 0 && isspace(pCompleto[i]) == 0)
			{
				pCompleto[0] = toupper(pCompleto[0]);

			}
			else
			{
				if (isspace(pCompleto[i]) && i < strlen(pCompleto) - 1)
				{
					pCompleto[i + 1] = toupper(pCompleto[i + 1]);
				}
			}
		}
	}
}
