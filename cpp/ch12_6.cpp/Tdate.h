#include <iostream>
#include <math.h>
using   namespace   std; 

class Tdate {
    public:
	Tdate();
	Tdate(int d);
	Tdate(int m, int d);
	Tdate(int m,int d,int y);
	
    protected:
	int month;
	int day;
	int year;

};

Tdate::Tdate() {
    month=1;
    day=1;
    year=1900;
}
