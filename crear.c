#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones.h"
int main(void)
{
    char *inputBuffer;
    //int contentLength;   
    char nombre[80];
    char descripcion[80];
    char directorio[80];
    char sololectura[80];

    FILE *fs;
    int estado;

    inputBuffer = entrada();
    
    separar(nombre, inputBuffer, '=');
    separar(nombre, inputBuffer, '&');
    separar(descripcion, inputBuffer, '=');
    separar(descripcion, inputBuffer, '&');
    separar(directorio, inputBuffer, '=');
    separar(directorio, inputBuffer, '&');
    separar(sololectura, inputBuffer, '=');
    separar(sololectura, inputBuffer, '&');
    
    printf ("Content-type:text/html\n\n");
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Creando [%s]</TITLE>\n",nombre);
    printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");

    inputBuffer = entrada();
    //contentLength = strlen(inputBuffer);
    //printf("<br>Datos Formulario: %s\n", inputBuffer);
    //printf("<br>Tama&ntildeo: %d\n",contentLength);

    if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
    if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");

    printf("<h5> Se esta creando [%s]</h5>",nombre);
   
    printf("<p> nuevo nombre: %s",nombre);
    printf("<p> descripcion: %s",descripcion);
    printf("<p> directorio: %s",directorio);
    printf("<p> solo lectura: %s",sololectura);
   

    printf("</div></body>");
    return 0;
}
