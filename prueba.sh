gcc -Wall -c funciones.c
gcc -Wall -c prueba.c
gcc -o cgi-bin/prueba funciones.o prueba.o
chmod gu+s cgi-bin/prueba


