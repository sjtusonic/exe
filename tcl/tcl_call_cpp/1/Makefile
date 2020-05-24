# 【Makefile】：
t = libfract.so
all: $t
clean:
	rm -f $t core
libfract.so: fract.c
	gcc -I. -shared -o $@ fract.c

