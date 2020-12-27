#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024


#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <unistd.h>


void separar(char *cadena, char *linea, char separador){
    int x, y;
    x = 0; y = 0;

    while ((linea[x]) && (linea[x] != separador)){
    	cadena[x] = linea[x];
    	x = x + 1;
    }
    
    cadena[x] = '\0';
    if (linea[x]) ++x;
        y = 0;
        while (linea[y] = linea[x]){
        	linea[y] = linea[x];
        	y++;
        	x++;
        }
}

int main(){
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char r_opcion[80];
 
    printf("Content-type:text/html\n\n");
    printf("<TITLE>Response</TITLE>\n");
    lenstr = getenv("CONTENT_LENGTH");

    if (lenstr!= NULL){
	contentLength = atoi(lenstr);
    }
    else 
        contentLength = 0;

        if (contentLength > sizeof(inputBuffer)-1)
    	contentLength = sizeof(inputBuffer)-1;

        i = 0;

        while (i < contentLength){
    	   x = fgetc(stdin);
        	if (x==EOF) break;
        	inputBuffer[i] = x;
        	i++;
        }

        inputBuffer[i] = '\0';
        contentLength = i;

    //printf("<br>Datos Formulario: %s\n", inputBuffer);
    //printf("<br>Tama&ntildeo: %d\n",contentLength);


    separar(r_opcion, inputBuffer, '=');
    separar(r_opcion, inputBuffer, '&');

    //  iniciar el servicio samba
    if(strcmp(r_opcion,"option1") == 0){
    	system("service smb start") || system("/etc/init.d/smb start");
        printf("<p> El servidor se ha iniciado");
    }
    //  parar el servicio samba
    if(strcmp(r_opcion,"option2") == 0){
        system("service smb stop") || system("/etc/init.d/smb stop");
        printf("<p> El servidor se ha detenido");	
    }
    //  reiniciar el servicio samba
    if(strcmp(r_opcion,"option3") == 0){
        system("service smb restart") || system("/etc/init.d/smb restart");
        printf("<p> El servidor se ha reiniciado");    
    }
    if(strcmp(r_opcion,"option4") == 0){
        printf("<p> Verificar version de Samba");
        system("smbd -V");
    }
    //Fin de las condiciones
printf("<p>%s",r_opcion);
return 0;
}
