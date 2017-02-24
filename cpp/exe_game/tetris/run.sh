 ctags -R --c++-kinds=+p --fields=+iaS --extra=+q


rm a.out; 
g++ -g -Wall -std=c++11 s.cpp Shape.class.cpp Matrix.class.cpp Display.class.cpp unit_test.cpp && ./a.out 
#rm a.out ; g++ -std=c++0x  -g -Wall s.cpp && ./a.out
