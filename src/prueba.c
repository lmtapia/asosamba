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
    char prueba[80];
    char inst[] = "inst";
    char comando1[] = "rpm -Vv samba | wc -l";
    char comando2[] = "service smb status | awk 'NR==3' | awk '{print $2}'";
    char **salida;
    printf ("Content-type:text/html\n\n");
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Comprobando samba</TITLE>\n");
    printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");

	inputBuffer = entrada();    
    // Cambiando nuevo ID y GID
	if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
	if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");
	//printf("<p>%s\n",inputBuffer);	
	separar(prueba, inputBuffer, '=');
	separar(prueba, inputBuffer, '&');
	//printf("%s</p>",prueba);
	if(strcmp(prueba,inst)==0){
		printf("<h2>Samba esta instalado?</h2>");
		//printf("%d",correr(comando1,"paquetes.txt"));
		salida = devolver(comando1);
		if(strcmp(salida[0],"1")==0)
			printf("<h3>%s</h3>","No instalado");
		else
			printf("<h3>%s</h3>","Instalado");
	}
	else{	
		printf("<h2>Samba esta corriendo?</h2>");
		//printf("%d",correr(comando2,"estado.txt"));
		salida = devolver(comando2);
		salida[0][strlen(salida[0])-2] = 'o';
		printf("<h3>%s%s</h3>","Samba esta ",salida[0]);
	}	
        //printf("\n<br>salida comando: %s",salida[0]);
	printf("</div>\n</body>");
    return 0;
}
