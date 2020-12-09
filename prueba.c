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
    int funciona;
    char inst[] = "inst";
    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Response</TITLE>\n");
    //printf("<head>\n<meta charset=\"utf-8\">\n</head>");
	
	inputBuffer = entrada();    
    // Cambiando nuevo ID y GID
	if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
	if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");
	//printf("<p>%s\n",inputBuffer);	
	separar(prueba, inputBuffer, '=');
	separar(prueba, inputBuffer, '&');
	//printf("%s</p>",prueba);
	if(strcmp(prueba,inst)==0){
		funciona = correr("rpm -Vv samba | wc-l","paquetes.txt");
		printf("<h2>instalado?</h2>");
	}
	else{	
		funciona = correr("service smb status | awk 'NR==3' | awk '{print $2}'","estado.txt");
		printf("<h2>corriendo?</h2>");
	}
	if(funciona){
		printf("funciona");
	}
	//system("/usr/sbin/useradd -d /home/nuevo1 -m nuevo1 2> error.txt");
    
    
    return 0;
}
