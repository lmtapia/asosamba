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
    char comando4[3][80] = {"vim /etc/samba/smb.conf -c +/workgroup +\":s/.*/workgroup = ",
	                "WORKGROUP",
                        "/\" +:wq"}; 
    char *comando;
    int estado;
    FILE *fs;

    printf ("Content-type:text/html\n\n");
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Cambio de workgroup</TITLE>\n");
    printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");    
	inputBuffer = entrada();    
    // Cambiando nuevo ID y GID
	if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
	if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");
	//printf("<p>%s\n",inputBuffer);	
	separar(comando4[1], inputBuffer, '=');
	separar(comando4[1], inputBuffer, '&');
	//printf("%s</p>",prueba);
	if(strcmp(comando4[1],"")==0){
	    printf("<h3>%s</h3>","El campo 'workgroup' no debe estar vacio");
		
	}
	else{	
	   comando = malloc(strlen(comando4[0])+strlen(comando4[1])+strlen(comando4[2]));
	   sprintf(comando,"%s%s%s",comando4[0],comando4[1],comando4[2]);
	   //printf("<h5>ejecutando: <code>%s</code></h4>",comando);
	   fs = abrir(comando);
	   estado = cerrar(fs);
   	   //printf("%d",estado);
	   if(estado!=0){
	   	printf("<h4>Algo fue mal</h4>");
	   }
	   else{
	   	printf("<h4>Parametro workgroup cambiado a %s</h4>",comando4[1]);
	   }	   
	}
	printf("</div></body>");	

	fs = abrir("smbcontrol all reload");
    cerrar(fs);
    return 0;
}
