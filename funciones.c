#include "funciones.h" 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 1024
/* Converts a hex character to its integer value */
char from_hex(char ch) {
  return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}
/* Converts an integer value to its hex character*/
char to_hex(char code) {
  static char hex[] = "0123456789abcdef";
  return hex[code & 15];
}

/* Returns a url-encoded version of str */
/* IMPORTANT: be sure to free() the returned string after use */
char *url_encode(char *str) {
  char *pstr = str, *buf = malloc(strlen(str) * 3 + 1), *pbuf = buf;
  while (*pstr) {
    if (isalnum(*pstr) || *pstr == '-' || *pstr == '_' || *pstr == '.' || *pstr == '~') 
      *pbuf++ = *pstr;
    else if (*pstr == ' ') 
      *pbuf++ = '+';
    else 
      *pbuf++ = '%', *pbuf++ = to_hex(*pstr >> 4), *pbuf++ = to_hex(*pstr & 15);
    pstr++;
  }
  *pbuf = '\0';
  return buf;
}

/* Returns a url-decoded version of str */
/* IMPORTANT: be sure to free() the returned string after use */
char *url_decode(char *str) {
  char *pstr = str, *buf = malloc(strlen(str) + 1), *pbuf = buf;
  while (*pstr) {
    if (*pstr == '%') {
      if (pstr[1] && pstr[2]) {
        *pbuf++ = from_hex(pstr[1]) << 4 | from_hex(pstr[2]);
        pstr += 2;
      }
    } else if (*pstr == '+') { 
      *pbuf++ = ' ';
    } else {
      *pbuf++ = *pstr;
    }
    pstr++;
  }
  *pbuf = '\0';
  return buf;
}

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
    return url_decode(inputBuffer);
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

FILE *abrir(char *comando){
    FILE *fp;
    fp = popen(comando, "r");
    return fp;
}

int cerrar(FILE *fp)
{   int status;
    status = pclose(fp);
        if (status == -1) {
            /* Error reported by pclose() */
        } else {
            /* Use macros described under wait() to inspect `status' in order
	     * to determine success/failure of command executed by popen() */
	}
    return status;
}


char **devolver(char *comando)
{
    FILE *fp;
    char **path;
    int i;
   
    path = (char **) malloc(MAXLEN*sizeof(char *));
    fp = abrir(comando);
    if (fp == NULL)
        printf("No se pudo ejecutar la accion");
    path[0] = malloc(MAXLEN*sizeof(char));
    i=0;
    while (fgets(path[i], MAXLEN, fp) != NULL){
        //printf("ejecutando ...\n");
	//path[i] = realloc(path[i],strlen(path[i])*sizeof(char));
	i++;
	path[i] = malloc(MAXLEN*sizeof(char));
    }
    path[i] = NULL;
    //path = realloc(path,(i+1)*sizeof(char *));
    
    cerrar(fp);
    return path;
}
