#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones.h"

int compartir(char *ini_nom,char *coment,char *path, char *inherit, char *read);

int main(void)
{
    char *inputBuffer;
    //int contentLength;   
    char nombre[80];
    char descripcion[80];
    char directorio[80];
    char sololectura[80];

    char ininombre[40]="\n[";
    char endnombre[5]="] ";
    char inicoment[60]="\n      comment = ";
    char ruta[60]     ="\n      path = ";
    char inherits[60] ="\n      inherit acls = yes";
    char readl[60]    ="\n      read only = ";
    
    int estado;
    FILE *fs;

    inputBuffer = entrada();

    separar(nombre, inputBuffer, '=');
    separar(nombre, inputBuffer, '&');
    separar(descripcion, inputBuffer, '=');
    separar(descripcion, inputBuffer, '&');
    separar(directorio, inputBuffer, '=');
    separar(directorio, inputBuffer, '&');
    separar(sololectura, inputBuffer, '=');
    separar(sololectura, inputBuffer, '&');
    
    printf ("Content-type:text/html\n\n");
    printf("<head>\n<meta charset=\"utf-8\">\n");
    printf("<TITLE>Creando [%s]</TITLE>\n",nombre);
    printf("<link rel=\"stylesheet\" href=\"/style.css\">\n</head>");
    printf("<body>\n<img src=\"https://www.samba.org/~metze/samba.logos/Samba_Logo_4c.png\" height=\"30\" align=\"left\">\n<br>");
    printf("<div class=\"card-body align-center\">\n<h1> ASOSAMBA </h1>\n");
    printf(" <h2> samba desde web + c</h2>\n</div>\n<div class=\"align-center\">\n");

    
    //contentLength = strlen(inputBuffer);
    //printf("<br>Datos Formulario: %s\n", inputBuffer);
    //printf("<br>Tama&ntildeo: %d\n",contentLength);

    if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
    if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");

    printf("<h5> Se esta creando [%s]</h5>",nombre);
   
    strcat(nombre, endnombre);
    strcat(ininombre, nombre);
    strcat(inicoment,descripcion);
    strcat(ruta, directorio);
    strcat(readl, sololectura);
    strcat(readl, "");
    estado = compartir(ininombre,inicoment, ruta, inherits, readl);
    
    if(estado == 0){
        printf("<h5>Se ha creado el recurso compartido %s</h5>",ininombre);
        //printf("<p>%s</p>",ininombre);
        printf("<p> %s</p>",inicoment);
        printf("<p> %s</p>",ruta);
        printf("<p> %s<p>",readl);
    }
    printf("</div></body>");

    fs = abrir("smbcontrol all reload");
    cerrar(fs);
    return 0;
}

int compartir(char *ininom,char *coment,char *path, char *inherit, char *read){
  int estado;
  //char buffer;
  FILE *smb = fopen("/etc/samba/smb.conf", "a");
  //FILE *smb = fopen("smbcreando","a");
  if(smb==NULL)
  {
	  printf("<h5> No se pude abrir el archivo</h5>");
  }
  else
  {
  	fputs(ininom, smb);
    	fputs(coment,smb);
    	fputs("\n      guest ok = No",smb);
	fputs(path, smb);
    	fputs(inherit, smb);
    	fputs(read, smb);
  }
  estado = fclose(smb);
  return estado;
}
