# asosamba
## Instalacion
_Para copiar desde linea de comandos ejecutar (superusuario):_
```sh
./copy.sh
service apache2 start
```
_abrir localhost/servidor.htm en el navegador_

### Requerimientos
```diff
+ HU01: verificar si el servidor Samba está instalado
+ HU02: ver el status el servidor Samba para poder iniciar, parar o reiniciar el servidor
+ HU3: configurar el parámetro workgroup 
+ HU4: cargar la configuración actual de recursos compartidos
- HU5: agregar nuevo recurso compartido para compartir archivos ya sea escritura o lectura
+ HU6: editar un recurso compartido para cambiar lectura/escritura o directorio
+ HU7:borrar un recurso compartido 
+ HU8: renombrar un recurso compartido
```

### lista de integrantes del proyecto en integrantes.txt

## Para desarrolladores
_Guardar en el directorio 'cgi-bin/' los ejecutables (codigo compilado) y en 'htdocs/' los archivos .htm_
### Cobertura de requerimientos
```hs
.
 |-- htdocs/
 |    |-- servidor.htm     :{HU1-HU4,HU6-HU8}
 |-- cgi-bin/
      |-- prueba           :{HU1,HU2}
      |-- ServidorSamba    :{HU2}
      |-- workgroup        :{HU3}
      |-- testparm         :{HU4}
      |-- edit1,edit2,edit3:{HU6-HU8}
```	
### Lista de comandos bash en comandos.txt

### Incluir en nuevo programa la libreria funciones
```c
#include "funciones.h"
```
### Para compilar nuevo codigo 
```sh
./compile.sh nuevo funciones
```
### Para el codigo existente
```sh
./compile.sh prueba funciones
./compile.sh testparm funciones
./compile.sh workgroup funciones
./compile.sh edit1 funciones
./compile.sh edit2 funciones
./compile.sh edit3 funciones
```

### funciones.h define las funciones: 
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
