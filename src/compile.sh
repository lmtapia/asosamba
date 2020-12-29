gcc -Wall -c $2.c
gcc -Wall -c $1.c
cd ..
gcc -o cgi-bin/$1 src/$2.o src/$1.o
chmod gu+s cgi-bin/$1


