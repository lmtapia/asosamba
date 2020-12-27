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
    printf("<TITLE>Ejecutando servidor</TITLE>\n");
    
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
    if(strcmp(r_opcion,"option1") == 0){
    	//system("service smb start") || system("/etc/init.d/smb start");
        fs = abrir("systemctl start smb nmb");
	estado = cerrar(fs);
	if(estado==0)
		printf("<p> El servidor se ha iniciado</p>");
    }
    //  parar el servicio samba
    if(strcmp(r_opcion,"option2") == 0){
        //system("service smb stop") || system("/etc/init.d/smb stop");
        fs = abrir("systemctl stop nmb smb");
        estado = cerrar(fs);
        if(estado==0)
               printf("<p> El servidor se ha detenido</p>");	
    }
    //  reiniciar el servicio samba
    if(strcmp(r_opcion,"option3") == 0){
        //system("service smb restart") || system("/etc/init.d/smb restart");
        fs = abrir("systemctl reload-or-restart smb nmb");
        estado = cerrar(fs);
        if(estado==0)
		printf("<p> El servidor se ha reiniciado</p>");    
    }
    if(strcmp(r_opcion,"option4") == 0){
        printf("<p> Verificar version de Samba</p>");
        fs = abrir("smbd -V");
	printf("<textarea disabled rows=\"4\" cols=\"50\">\n");
	version = (char *) malloc(MAXLEN * sizeof(char));		
	while(fgets(version,MAXLEN*sizeof(char),fs)!=NULL)
	{	printf(version);
	}
	printf("</textarea>\n");
	estado = cerrar(fs);
    }
    if(estado!=0)
	printf("<p> No se pudo completar la accion</p>");
    //Fin de las condiciones
return 0;
}
