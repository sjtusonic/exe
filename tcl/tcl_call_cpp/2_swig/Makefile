t = fract_wrap.c libfract.so
all: $t
clean:
	rm -f $t core *.doc *.o
fract_wrap.c: fract.i
	swig -tcl fract.i
libfract.so:fract_wrap.c
	gcc -c fract.c fract_wrap.c -I/home/zz/Downloads/tcl8.6.10/generic
