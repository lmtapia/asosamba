gcc -Wall -c src/funciones.c -o src/funciones.o
for F in src/*.c; 
do      
   if [[ ${F:4: -2} != 'funciones' ]]
   then	echo compilando ${F:4: -2}
	gcc -Wall -c $F  -o ${F:0: -2}.o 
        gcc -o cgi-bin/${F:4: -2} src/funciones.o ${F:0: -2}.o
        chmod gu+s cgi-bin/${F:4: -2}
   fi
done


