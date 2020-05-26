	echo "--------------------------------->"
	gcc -c fract.c fract_wrap.c -fPIC -I/home/zz/Downloads/tcl8.6.10/generic
	gcc -shared -fPIC -o libfract.so fract_wrap.o fract.o 
/usr/bin/tclsh test.tcl 
