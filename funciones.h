#include <stdio.h>
#ifndef FUNCIONES_DOT_H   
#define FUNCIONES_DOT_H   
//procesa el contenido de un request de un form
char* entrada(); 

//separa una linea de entrada en una cadena
void separar(char *cadena, char *linea, char separador);

//ejecuta un comando y guarda su salida en archivo
int correr(char *comando,char *archivo);

//devuelve la salida de un comando
char **devolver(char *comando);
//igual al anterior con numero maximo de filas variable 
char **devolverNFilas(char *comando,int filas);

//devuelve el puntero al stream de un comando 
FILE *abrir(char *comando);

//cierra el stream de FILE
int cerrar(FILE *fs);

#endif /* FOO_DOT_H */

