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
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Editar un recurso compartido</TITLE>\n");
   printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");

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
	
	printf("%s%s%s%s%s%s\n","<option required onchange=\"this.form.submit()\" value=\"",recursos[i],siguiente,"\">",recursos[i],"</option>");
    	i++;
    }
    printf("<INPUT type=\"SUBMIT\" class=\"btn btn-primary\" VALUE=\"Ver\"/>\n");
    printf("</FORM>");
    printf("</div></body>");
    return 0;
}
