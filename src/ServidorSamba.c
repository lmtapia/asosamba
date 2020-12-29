#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024


#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <unistd.h>
#include "funciones.h"

int main(){
    //char *lenstr;
    char *inputBuffer;
    //int contentLength;
    char r_opcion[80];
    FILE *fs;
    int estado=MAXLEN;
    char *version;
    printf("Content-type:text/html\n\n");
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Ejecutando servidor</TITLE>\n");
    printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");
    
    // Cambiando nuevo ID y GID
    if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
    if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");

    inputBuffer = entrada();

    //printf("<br>Datos Formulario: %s\n", inputBuffer);
    //printf("<br>Tama&ntildeo: %d\n",contentLength);

    separar(r_opcion, inputBuffer, '=');
    separar(r_opcion, inputBuffer, '&');

    printf("<h5>Ejecutando accion: %s<h5>",r_opcion);
    //  iniciar el servicio samba
    if(strcmp(r_opcion,"iniciar") == 0){
    	//system("service smb start") || system("/etc/init.d/smb start");
        fs = abrir("systemctl start smb nmb");
	estado = cerrar(fs);
	if(estado==0)
		printf("<h5> El servidor se ha iniciado</h5>");
    }
    //  parar el servicio samba
    if(strcmp(r_opcion,"parar") == 0){
        //system("service smb stop") || system("/etc/init.d/smb stop");
        fs = abrir("systemctl stop nmb smb");
        estado = cerrar(fs);
        if(estado==0)
               printf("<h5> El servidor se ha detenido</h5>");	
    }
    //  reiniciar el servicio samba
    if(strcmp(r_opcion,"reiniciar") == 0){
        //system("service smb restart") || system("/etc/init.d/smb restart");
        fs = abrir("systemctl reload-or-restart smb nmb");
        estado = cerrar(fs);
        if(estado==0)
		printf("<h5> El servidor se ha reiniciado</h5>");    
    }
    if(strcmp(r_opcion,"version") == 0){
        printf("<h4> Verificar version de Samba</h4>");
        fs = abrir("smbd -V");
	printf("<textarea disabled rows=\"4\" cols=\"40\">\n");
	version = (char *) malloc(MAXLEN * sizeof(char));		
	while(fgets(version,MAXLEN*sizeof(char),fs)!=NULL){	
		printf(version);
	}
	printf("</textarea>\n");
	estado = cerrar(fs);
    }
    if(estado!=0)
	printf("<h5> No se pudo completar la accion</h5>");
    //Fin de las condiciones
    printf("</div></body>");
    return 0;
}
