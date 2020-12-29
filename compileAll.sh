gcc -Wall -c funciones.c
for F in *.c; 
do 
   if [[ $F != 'funciones.c' ]]
   then	echo compilando $F
	gcc -Wall -c $F 
        gcc -o cgi-bin/${F%.c} funciones.o ${F%.c}.o
        chmod gu+s cgi-bin/${F%.c}
   fi
done


