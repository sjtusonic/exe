  /usr/bin/ctags -R --sort=yes --c++-kinds=+pl --fields=+iaSKz . 
 rm a.out;
 rm compile.log;
 rm out.log 
g++ -g -Wall -std=c++11 GraphBase.cpp Graph.cpp main.cpp > compile.log 2>&1 &&  ./a.out > out.log 2>&1
 #g++ -g -Wall -std=c++11 main.cpp > compile.log 2>&1 &&  ./a.out > out.log 2>&1
 grep --color error compile.log 
#rm a.out; g++ -E -v -g -Wall -std=c++11 GraphBase.cpp main.cpp; ./a.out
