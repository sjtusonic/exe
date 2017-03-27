 #ctags -R --c++-kinds=+p --fields=+iaS --extra=+q


rm a.out; 

# only do it once:
#g++ tests-main.cpp -c 

#g++ tests-main.o tests-factorial.cpp -o tests && ./tests -r compact

#g++ -g -Wall -std=c++11 tests-main.o tests.cpp s.cpp Shape.class.cpp Matrix.class.cpp Display.class.cpp unit_test.cpp && ./a.out 
g++ -g -Wall -std=c++11 s.cpp Shape.class.cpp Matrix.class.cpp Display.class.cpp unit_test.cpp lib.cpp && ./a.out 
#rm a.out ; g++ -std=c++0x  -g -Wall s.cpp && ./a.out
