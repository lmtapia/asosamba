#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "funciones.h"

int main(void)
{	
    //char *inputBuffer;
    char comandorecursos[] ="cat /etc/samba/smb.conf | grep ]"; 
    char **recursos;
    //int estado;
    //FILE *fs;
    int i = 1;
    char *siguiente;
    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Editar un recurso compartido</TITLE>\n");
    //printf("<head>\n<meta charset=\"utf-8\">\n</head>");
    //inputBuffer = entrada();    
    // Cambiando nuevo ID y GID
    if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
    if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");
    printf("<FORM ACTION=\"edit2\" METHOD=\"POST\">\n");	
    printf("Recurso a editar: <select name=recurso>\n");
    recursos = devolver(comandorecursos);
    if(recursos[1]!=NULL)
	recursos[1][strlen(recursos[1])-1]=0;
    while(i<1024 && recursos[i]!=NULL)
    {   if(i+1<1024 && recursos[i+1]!=NULL)
	{   recursos[i+1][strlen(recursos[i+1])-1]=0;
	    siguiente = recursos[i+1];
	}
	else
	{    siguiente = malloc(10);
	     sprintf(siguiente,"");	     	     
	}
	
	printf("%s%s%s%s%s\n","<option required onchange=\"this.form.submit()\" value=\"",recursos[i],siguiente,"\">",recursos[i]);
    	i++;
    }
    printf("<INPUT type=\"SUBMIT\" VALUE=\"Ver\">\n");
    printf("</FORM>");
    return 0;
}
