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
    int contentLength;
    char prueba[80];
    char inst[] = "inst";
    char comando4[] = "testparm -s";
    char **salida;
    int i;

    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Response</TITLE>\n");  
    
    inputBuffer = entrada();
    contentLength = strlen(inputBuffer);
    printf("<br>Datos Formulario: %s\n", inputBuffer);
    printf("<br>Tama&ntildeo: %d\n",contentLength);

    salida = devolver(comando4);
    printf("<textarea id=\"test\" name\"test\" rows=30 cols=50>\n");
    i=0;
    while(i<1024 && salida[i]!=NULL){	
    	printf(salida[i]);
    	i++;
    }
    printf("%d lineas",i);
    printf("\n</textarea>\n");
    
    
   return 0;
}
