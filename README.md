# asosamba
Para copiar desde linea de comandos ejecutar (superusuario):
```sh
./copy.sh
service apache2 start
```

Guardar en el directorio 'cgi-bin/' los ejecutables (codigo compilado) y en 'htdocs/' los archivos .htm

Incluir en nuevo programa la libreria funciones
```c
#include "funciones.h"
```
que define las funciones: 
```c
//funcion que procesa el contenido de un request de un form
char* entrada(); 

//funcion que separa una linea de entrada en una cadena
void separar(char *cadena, char *linea, char separador);

//funcion que ejecuta un comando y guerda su salida en archivo
int correr(char *comando,char *archivo);

//funcion que devuelve la salida de un comando
char **devolver(char *comando);
```

Para compilar nuevo codigo 
```sh
./compile.sh nuevo funciones
```

Para el codigo existente
```sh
./compile.sh prueba funciones
./compile.sh testparm funciones
```
