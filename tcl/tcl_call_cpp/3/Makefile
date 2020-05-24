t = main
# TCL_LIBS = -L/usr/lib -ltcl8.6
TCL_LIBS = -L/home/zz/Downloads/tcl8.6.10/library -ltcl8.6
all: $t
clean:
	rm -f $t core
main:main.c fract.c
	gcc -I. -I/home/zz/Downloads/tcl8.6.10/generic ${TCL_LIBS} -o $@ main.c fract.c 
