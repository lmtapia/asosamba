#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
/*#define MAXLEN 1024

//entrada: procesa la entrada y la devuelve en un arreglo por su puntero
char* entrada(){
    char *lenstr;
    char *inputBuffer;
    int contentLength;
    int i;
    int x;
    
    inputBuffer = malloc(MAXLEN);
    lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
    contentLength = atoi(lenstr);
    }
    else contentLength = 0;
    
    if (contentLength > MAXLEN-1)
    contentLength = MAXLEN*-1;

    i = 0;
    
    while (i < contentLength){

    x = fgetc(stdin);
    if (x==EOF) break;
    inputBuffer[i] = x;
    i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;
    return inputBuffer;
}
// Separar: separa datos del formulario
void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while (linea[y] = linea[x])
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}
*/
int main(void)
{
    char *inputBuffer;
    int contentLength;
    //int i;
    //char x;
    char mensaje[80];
    char usuario[80];
    char clave[80];
    char shell[80];
    
    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Response</TITLE>\n");
    
    inputBuffer = entrada();
    contentLength = strlen(inputBuffer);
    printf("<br>Datos Formulario: %s\n", inputBuffer);
    printf("<br>Tama&ntildeo: %d\n",contentLength);

    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');
    separar(clave, inputBuffer, '=');
    separar(clave, inputBuffer, '&');
    separar(shell, inputBuffer, '=');
    separar(shell, inputBuffer, '&');


    printf("<p> Mensaje: %s",mensaje);
    printf("<p> Usuario: %s",usuario);
    printf("<p> Clave: %s",clave);
    printf("<p> Shell: %s",shell);
  
    return 0;
}

