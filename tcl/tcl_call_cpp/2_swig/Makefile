t = fract_wrap.c libfract.so
all: $t
clean:
	rm -f $t core *.doc *.o
fract_wrap.c: fract.i
	swig -tcl8 fract.i
libfract.so:fract_wrap.c
	gcc -c fract.c fract_wrap.c -fPIC -I/home/zz/Downloads/tcl8.6.10/generic
	gcc -shared -fPIC -o libfract.so fract_wrap.o fract.o 
