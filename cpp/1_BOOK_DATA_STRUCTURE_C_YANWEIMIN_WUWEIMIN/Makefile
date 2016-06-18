DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard ${DIR_SRC}/*.cpp)  
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC})) 

TARGET = main

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = g++
CFLAGS = -v -g -Wall -I${DIR_INC}
#CFLAGS = -v -g -I${DIR_INC}

${BIN_TARGET}:${OBJ}
	make ctags
	$(CC) $(OBJ)  -o $@

${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c  $< -o $@ > compile.log
.PHONY:clean run
clean:
	#find ${DIR_OBJ} -name *.o -exec rm -rf {}
	rm ${DIR_OBJ}/*.o
run:
	${BIN_TARGET}
debug:
	gdb -f ${BIN_TARGET}
ctags:
	ctags -R --sort=yes --c++-kinds=+px --fields=+iaS --extra=+q
ctags_system:
	ctags -R --sort=yes -I __THROW –file-scope=yes –langmap=c:+.h –languages=c,c++ –links=yes –c-kinds=+p --fields=+S -R -f ~/.vim/systags /usr/include /usr/local/include
valgrind:
	valgrind --tool=memcheck --show-reachable=yes --leak-check=yes bin/main
