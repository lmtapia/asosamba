# asosamba
para correr, 
desde linea de comandos ejecutar (superusuario):
```sh
sh prueba.sh
sh copy.sh
```
Incluir en nuevo programa la libreria funciones
```c
#include "funciones.h"
```
que define las funciones: 
```c
char* entrada(); 
void separar(char *cadena, char *linea, char separador);
int correr(char comando[],char archivo[]);
```

Para compilar nuevo codigo 
```sh
gcc -Wall -c nuevo.c
gcc -o cgi-bi/nuevo funciones.o nuevo.o 
chmod gu+s cgi-bin/nuevo
```
