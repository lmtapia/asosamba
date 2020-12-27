#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones.h"
int main(void)
{
    char *inputBuffer;
    //int contentLength;
    char recurso[80];
    char siguiente[80];
    char nuevonombre[80];
    char sololectura[80];
    char directorio[80];
    char borrar[80];
    char *comando = malloc(1024);
    char comando6lect[3][80] = {"vi /etc/samba/smb.conf -c +/", /*RECURSO */
	                        " +\"/read only\" +\":s/.*/read only = ", /*SI,NO*/
		                "/\" +:wq"};
    char comando6dir[3][80] = {"vi /etc/samba/smb.conf -c +/",/*RECURSO*/ 
	                      " +\"/path\" +\":s#.*#path = ",/* nuevo/dir */
			      "#\" +:wq"};
    char comando7[6][80]= {"cat /etc/samba/smb.conf | sed -e '/",/*RECURSO*/
	                  "/,$d'> borrando",
			  "cat /etc/samba/smb.conf | sed -s -n '/",/*SIGUIENTE*/
			  "/,$p' >> borrando",
			  "cp borrando",
			  " /etc/samba/smb.conf"};

    char comando8[3][80] = {"vi /etc/samba/smb.conf -c +/", /*RECURSO*/
	                    " +\":s/.*/[", /*nuevo*/
	                    "]/\" +:wq"};
    FILE *fs;
    int estado;

    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Editando</TITLE>\n");
    
    inputBuffer = entrada();
    //contentLength = strlen(inputBuffer);
    //printf("<br>Datos Formulario: %s\n", inputBuffer);
    //printf("<br>Tama&ntildeo: %d\n",contentLength);

    if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
    if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");

    separar(recurso, inputBuffer, '=');
    separar(recurso, inputBuffer, '&');
    separar(siguiente, inputBuffer, '=');
    separar(siguiente, inputBuffer, '&');
    separar(sololectura, inputBuffer, '=');
    separar(sololectura, inputBuffer, '&');
    separar(directorio, inputBuffer, '=');
    separar(directorio, inputBuffer, '&');
    separar(nuevonombre, inputBuffer, '=');
    separar(nuevonombre, inputBuffer, '&');
    separar(borrar, inputBuffer, '=');
    separar(borrar, inputBuffer, '&');

    printf("<h5> Se esta editando [%s</h5>",recurso);
    /*
    printf("<p> nuevo nombre: %s",nuevonombre);
    printf("<p> solo lectura: %s",sololectura);
    printf("<p> directorio: %s",directorio);
    printf("<p> borrar: %s",borrar);
    */
    if(strcmp(borrar,"SI")==0)
    {
    	printf("<p>borrando </p>\n");
	sprintf(comando,"%s%s%s[%s",comando7[0],recurso,comando7[1],recurso);
        //printf("<p>%s</p>",comando);
	fs =  abrir(comando);
        estado = cerrar(fs);
        if(estado ==0){
                printf("<p>copiando recursos antes de [%s</p>",recurso);
        }
	if(strcmp(siguiente,""))
	{   sprintf(comando,"%s%s%s[%s",comando7[2],siguiente,comando7[3],recurso);
            //printf("<p>%s</p>",comando);
            fs =  abrir(comando);
            estado = cerrar(fs);
            if(estado ==0){
                printf("<p>copiando recursos despues de [%s</p>",recurso);
            }
	}
	sprintf(comando,"%s[%s%s",comando7[4],recurso,comando7[5]);
	//printf("<p>%s</p>",comando);
	fs =  abrir(comando);
        estado = cerrar(fs);
        if(estado ==0){
                printf("<p>borrado</p>");
        }
    }
    else
    {
    	if(strcmp(sololectura,"")!=0)
	{
           printf("<p>cambiando la opcion de Solo lectura a  %s</p>\n",sololectura);
	   sprintf(comando,"%s%s%s%s%s",comando6lect[0],recurso,comando6lect[1],
			   sololectura,comando6lect[2]);
	   //printf("<p>%s</p>",comando);
           fs =  abrir(comando);
	   estado = cerrar(fs);
	   if(estado ==0){
	   	printf("<p>Completado</p>");
	   }
	}
	if(strcmp(directorio,"")!=0)
	{
	   printf("<p>cambiando la opcion de Directorio a  %s</p>\n",directorio);
	   sprintf(comando,"%s%s%s%s%s",comando6dir[0],recurso,comando6dir[1],
                           directorio,comando6dir[2]);
           //printf("<p>%s</p>",comando);
	   fs =  abrir(comando);
           estado = cerrar(fs);
           if(estado ==0){
                printf("<p>Completado</p>");
           }

	}
	if(strcmp(nuevonombre,"")!=0)
	{
           printf("<p>cambiando el nombre del recurso  a  %s</p>\n",nuevonombre);
	   sprintf(comando,"%s%s%s%s%s",comando8[0],recurso,comando8[1],
                           nuevonombre,comando8[2]);
           //printf("<p>%s</p>",comando);
	   fs =  abrir(comando);
           estado = cerrar(fs);
           if(estado ==0){
                printf("<p>Completado</p>");
           }

	}	   
    }
    return 0;
}

