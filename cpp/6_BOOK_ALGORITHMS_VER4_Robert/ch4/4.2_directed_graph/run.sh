  /usr/bin/ctags -R --sort=yes --c++-kinds=+pl --fields=+iaSKz . 
 rm a.out;
 rm compile.log;
 rm out.log 
g++ -g -Wall -std=c++11 Digraph.cpp  main.cpp > compile.log 2>&1 &&  ./a.out > out.log 2>&1
 grep --color error compile.log 
#rm a.out; g++ -E -v -g -Wall -std=c++11 Graph.cpp main.cpp; ./a.out


# dot2svg
for i in `ls *dot`
do
	echo $i
	to=$i.svg
	dot -Tsvg $i -o $to
done
