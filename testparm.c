#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "funciones.h"

int main(void)
{	
    char *inputBuffer;
    //int contentLength;
    char prueba[80];
    char comando4[12] = "testparm -s";
    char comandoconf[] = "cat /etc/samba/smb.conf";
    char *linea;
    int i;
    FILE *fs;
    int estado;

    printf ("Content-type:text/html\n\n");
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Cargando configuracion</TITLE>\n");  
    printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");

    inputBuffer = entrada();
    //contentLength = strlen(inputBuffer);
    //printf("<br>Datos Formulario: %s\n", inputBuffer);
    //printf("<br>Tama&ntildeo: %d\n",contentLength);
    separar(prueba,inputBuffer,'=');
    separar(prueba,inputBuffer,'&');
    if(strcmp(prueba,"resumen")==0){
        printf("<p>Este es un resumen de las configuraciones de samba,");
    	printf("no muestra las configuraciones por defecto </p>");
    	fs = abrir(comando4);
    }
    else{
    	printf("<p>Este es un detalle de las  configuraciones de samba \n");
        printf("en el archivo <code>/etc/samba/smb.conf</code>,\n");
        printf("puede diferir de la configuracion actual, ");
	printf(" vea resumen para comprobar</p>\n");
	//comando4[(sizeof comando4/ sizeof comando4[0]) -1]='v';
	fs = abrir(comandoconf);
    }
    printf("<textarea id=\"test\" name\"test\" rows=25  cols=40>\n");
    i=0;
    linea = (char *) malloc(2048*sizeof(char));
    while(fgets(linea, 2048*sizeof(char), fs) != NULL){	
    	printf(linea);
    	i++;
    }
    free(linea);
    estado = cerrar(fs);
    printf("\n</textarea>\n");
    printf("<p>%d lineas</p>",i);
    printf("</div></body>");    
    
   return estado;
}
