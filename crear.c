#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones.h"
int compartir(  char *ini_nom,char *path, char *inherit, char *read);

int main(void)
{
    char *inputBuffer;
    //int contentLength;   
    char nombre[80];
    char descripcion[80];
    char directorio[80];
    char sololectura[80];

    char ininom[40]="[";
    char endnom[5]="] \n ";
    char inicoment[60]="      comment = ";
    char ruta[60]="\n     path = ";
    char inherits[60]="\n      inherit acls = yes";
    char readl[60]="\n      read only = ";
    
    int estado;

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
   
    strcat(nombre, endnom);
    strcat(ininom, nombre);
    strcat(inicoment,coment);
    strcat(ruta, rutaDir);
    strcat(readl, read);
    estado = compartir(ininombre,coment, ruta, inherits, read_l);
    if(estado == 0){
        printf("<h5>Se ha creado el recurso compartido ",ininombre);
        //printf("<p> nombre: %s",nombre);
        printf("<p> descripcion: %s",descripcion);
        printf("<p> directorio: %s",directorio);
        printf("<p> solo lectura: %s",sololectura);
    }
    printf("</div></body>");

    fs = abrir("smbcontrol all reload");
    cerrar(fs);
    return 0;
}

int compartir(  char *ini_nom,char *path, char *inherit, char *read){
  int estado=0;
  char buffer;
  FILE *smb = fopen("/etc/samba/smb.conf", "a");
    
    fputs(ini, smb);
    fputs(path, smb);
    fputs(inherit, smb);
    fputs(read, smb);
  estado = fclose(smb);
  return estado;
}