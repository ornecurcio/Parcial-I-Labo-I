/*
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */

#ifndef UTN_H_
#define UTN_H_

void getString(char mensaje[], char imput[]);
void getChar(char* mensaje, char* rta);
/**
 * \brief
 * \param char* cadena es un puntero donde se va a guardar el string
 * \param longitud, la longitud del cadena de caracteres
 * return Retorna 0 si se valido con exito la toma del string.
 */
int myGets(char* cadena, int longitud);
/**
 * \brief OBTIENE UN NUMERO ENTERO
 * \param pResultado es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si se valido con exito o -1, si es error.
 */
int getInt(int* pResultado);
/**
 * \brief valida que la cadena obtenida sea numerica
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si los caracteres son todos numericos, tomando en cuenta que puede haber
 * un signo + o menos en la posicion cero,  o 0, SI ES ERROR.
 */
int esNumerica(char* cadena, int longitud);

/*obtiene un numero entero, asigno el resultado a un espacio de memoria,
 * muestra un mensaje de ingreso de dato, un mensaje de error si la validacion esta mal,
 * valida contra minimo y maximo
 * estable cantidad de reintentos de error.
 * */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * \brief valida que la cadena obtenida es FLOTANTE
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */
int getFloat(float* pResultado);
/**
 * \brief valida que la cadena obtenida sea flotante
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si la cadena es flotante,o 0, SI ES ERROR.
 */
int esFlotante(char* cadena, int longitud);
/**
 * \brief Solicita un numero FLOTANTE al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje es el mensaje a ser mostrado al usuario
 * \param mensajeError es el mensaje a ser mostrado al usuario cuando lo ingresado es incorrecto
 * \param minimo es el numero minimo a ser aceptado
 * \param maximo es el numero maximo a ser aceptado
 *  \return Retorna 0 si se obtuvo el numero o, 1 SI ES ERROR.
 */
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int inicializarArrayFlotante(float pArray[], int cantidadDeArray);
int imprimirArrayFlotante(float pArray[], int cantidadDeArray);
int inicializarArrayCadena(char pArray[][20], int cantidadDeArray);
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
/**
 * \brief 	Verifica una cadena recibida como parametro para determinir
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int longitud, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esNombre(char* cadena,int longitud);
/**
 * \brief valida que la cadena obtenida es Nombre
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */
int getNombre(char* pResultado, int longitud);

/**
 * \brief Solicita un nombre al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 */
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud);

int esSoloLetra(char *pResultado) ;
int esLetraConEspacio(char *pResultado);
int esTelefonoValido(char* cadena);
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos);

void FormaApellidoNombre(char *pNombre, char *pApellido, char *pCompleto);
int esCUIT(char* cadena);
int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
int utn_getCaracterSN(void);
#endif /* UTN_H_ */
