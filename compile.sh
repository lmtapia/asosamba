gcc -Wall -c $2.c
gcc -Wall -c $1.c
gcc -o cgi-bin/$1 $2.o $1.o
chmod gu+s cgi-bin/$1


