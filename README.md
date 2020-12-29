# asosamba
## Instalación
_Descomprimir_
```sh
tar -xzvf asosamba.tar.gz
```
_Recompilar (opcional)_
```sh
./asosamba/compileAll.sh
```
_Copiar (ejecutar como superusuario):_
```sh
cd asosamba
./copy.sh
service apache2 start
```
_abrir localhost/servidor.htm en el navegador_

_configurar contraseña para cada usuario_
```sh
smbpassw -a usuario
```
### Requerimientos
```diff
+ HU01: verificar si el servidor Samba está instalado
+ HU02: ver el status el servidor Samba para poder iniciar, parar o reiniciar el servidor
+ HU3: configurar el parámetro workgroup 
+ HU4: cargar la configuración actual de recursos compartidos
+ HU5: agregar nuevo recurso compartido para compartir archivos ya sea escritura o lectura
+ HU6: editar un recurso compartido para cambiar lectura/escritura o directorio
+ HU7:borrar un recurso compartido 
+ HU8: renombrar un recurso compartido

HU1 a HU4 estan disponibles en servidor.htm 
HU5 a HU8 se encuentran desde la ultima opcion de servidor.htm 
```
### lista de integrantes del proyecto en integrantes.txt

## Para desarrolladores
_Guardar en el directorio 'cgi-bin/' los ejecutables (codigo compilado) y en 'htdocs/' los archivos .htm_
### para comprimir
```sh
tar -czvf asosamba.tar.gz asosamba/
```
### Cobertura de requerimientos
```c
.
 |-- htdocs/
 |    |-- servidor.htm     :{HU1-8}
 |-- cgi-bin/
      |-- prueba           :{HU1,HU2}
      |-- edit1            :{HU5-8}
      |-- edit2,edit3      :{HU6-8}
      |-- ServidorSamba    :{HU2}
      |-- workgroup        :{HU3}
      |-- testparm         :{HU4}
      |-- crear            :{HU5}
```	
### Lista de comandos bash en comandos.txt

### Incluir en nuevo programa la libreria funciones
```c
#include "funciones.h"
```
### Para compilar nuevo codigo desde src/
```sh
./compile.sh nuevo funciones
```
### Para el codigo existente
```sh
./compileAll.sh
```
o uno por uno desde src/
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
### Estructura de archivos
```c
.
├── cgi-bin
│   ├── crear
│   ├── edit1
│   ├── edit2
│   ├── edit3
│   ├── leerform
│   ├── prueba
│   ├── ServidorSamba
│   ├── testparm
│   └── workgroup
├── comandos.txt
├── compileAll.sh
├── copy.sh
├── htdocs
│   ├── bootstrap.css
│   ├── form2.htm
│   ├── servidor.htm
│   ├── style.css
│   └── Wallpaper-idea-swirl.png
├── integrantes.txt
├── README.md
├── smb.conf.last
└── src
    ├── compile.sh
    ├── crear.c
    ├── crear.o
    ├── edit1.c
    ├── edit1.o
    ├── edit2.c
    ├── edit2.o
    ├── edit3.c
    ├── edit3.o
    ├── funciones.c
    ├── funciones.h
    ├── funciones.o
    ├── leerform.c
    ├── leerform.o
    ├── leerform.sh
    ├── prueba.c
    ├── prueba.o
    ├── ServidorSamba.c
    ├── ServidorSamba.o
    ├── testparm.c
    ├── testparm.o
    ├── workgroup.c
    └── workgroup.o
```
