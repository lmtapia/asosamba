#ifndef FUNCIONES_DOT_H   
#define FUNCIONES_DOT_H   
//funcion que procesa el contenido de un request de un form
char* entrada(); 

//funcion que separa una linea de entrada en una cadena
void separar(char *cadena, char *linea, char separador);

//funcion que ejecuta un comando y guerda su salida en archivo
int correr(char *comando,char *archivo);

//funcion que devuelve la salida de un comando
char *devolver(char *comando);

#endif /* FOO_DOT_H */

