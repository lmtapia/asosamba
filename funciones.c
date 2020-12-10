#include "funciones.h" 
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024

char* entrada(){
    char *lenstr;
    char *inputBuffer;
    int contentLength;
    int i;
    int x;
    
    inputBuffer = malloc(MAXLEN);
    lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
    contentLength = atoi(lenstr);
    }
    else contentLength = 0;
    
    if (contentLength > MAXLEN-1)
    contentLength = MAXLEN*-1;

    i = 0;
    
    while (i < contentLength){

    x = fgetc(stdin);
    if (x==EOF) break;
    inputBuffer[i] = x;
    i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;
    return inputBuffer;
}

void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while ((linea[y] = linea[x]))
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}

int correr(char *comando,char *archivo)
{	int length = sizeof(comando) + sizeof(archivo)+3;
	char comandoArchivo[length];
	int n;
	sprintf(comandoArchivo, "%s > %s", comando, archivo);
	n = system(comandoArchivo);
    return n;
}

char* devolver(char *comando){
    FILE *fp;
    int status;
    char path[PATH_MAX];

    fp = popen(comando, "r");
    if (fp == NULL)
        /* Handle error */;

    while (fgets(path, PATH_MAX, fp) != NULL){
        printf("%s", path);
    }


    status = pclose(fp);
    if (status == -1) {
        /* Error reported by pclose() */
    } else {
        /* Use macros described under wait() to inspect `status' in order
           to determine success/failure of command executed by popen() */
    }
    return path;
}
