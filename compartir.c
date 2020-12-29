#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define LIMITE 10000
#define MAXLEN 1024
char rutaDir[50];

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
int main(void){
  
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char nombre[80];
    char coment[60];
    char path[60];
    char read[60];
    int Uid, Gid, iUid, iGid;

    //Obtener el ID/GID
    Uid = getuid();
    Gid = getgid();
    if((setuid(0)) < 0) printf("\n<br>setuid: operacion no permitida\n");
    if((setgid(0)) < 0) printf("\n<br>setgid: operacion no permitida\n");
    iUid = getuid();
    iGid = getgid();
    printf("Content-type:text/html\n\n");
    printf("<TITLE>WorkGroup</TITLE>\n");
    
    inputBuffer[i] = entrada();
    
    char ininom[40]="[";
    char endnom[5]="] \n ";
    char inicoment[60]="      comment = ";
    char ruta[60]="\n     path = ";
    char inherits[60]="\n      inherit acls = yes";
    char readl[60]="\n      read only = ";
    separar(nombre, inputBuffer, '=');
    separar(nombre, inputBuffer, '&');
    separar(coment, inputBuffer, '=');
    separar(coment, inputBuffer, '&');
    separar(path, inputBuffer, '=');
    separar(path, inputBuffer, '&');
    separar(read, inputBuffer, '=');
    separar(read, inputBuffer, '&');

    strcat(nombre, endnom);
    strcat(ininom, nombre);
    strcat(inicoment,coment);
    strcat(ruta, rutaDir);
    strcat(readl, read);
    compartir(nombre,coment, ruta, inherits, read_l);

    printf("Nuevo recurso compartido");
}
