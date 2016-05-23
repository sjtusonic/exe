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
    public:
	void show ();
	int CalculateJulianDay();
	int invCJD(int jd);
};

Tdate::Tdate() {
    month=1;
    day=1;
    year=1900;
}

Tdate::Tdate(int y, int m, int d) {
    month=m;
    day=d;
    year=y;
}

void Tdate::show() {
    cout<<"NOW is"<<year<<"-"<<month<<"-"<<day<<endl;
    cout<<"JD is"<<CalculateJulianDay()<<endl;
}

//int Tdate::CalculateJulianDay(int year, int month, int day)
int Tdate::CalculateJulianDay()
{

         int B = 0;

     

         if(month <= 2)

         {

	         month += 12;

	         year -= 1;

	     }

	     //if(IsGregorianDays(year, month, day))
	     if(1)

	     {

	             B = year / 100;

	             B = 2 - B + year / 400;

	         }

	     

	         double dd = day + 0.5000115740; /*本日12:00后才是儒略日的开始(过一秒钟)*/

	         return int(365.25 * (year + 4716) + 0.01) + int(30.60001 * (month + 1)) + dd + B - 1524.5;

}

int Tdate::invCJD(int jd){

if (CalculateJulianDay()<jd) {
    while (CalculateJulianDay()<jd) { year++;}
    year--;
    while (CalculateJulianDay()<jd) { month++;}
    month--;
    while (CalculateJulianDay()<jd) { day++;}
    day--;
} 



if (CalculateJulianDay()>jd) {
    while (CalculateJulianDay()>jd) { year--;show();}
    year++;
    while (CalculateJulianDay()>jd) { month--;}
    month++;
    while (CalculateJulianDay()>jd) { day--;}
    day++;
}   
    return 1;
}

int main () {
    //Tdate aday;
    //int gre=aday.CalculateJulianDay();
    Tdate bday(1996,1,1);
    bday.show();
    //cout <<bday.CalculateJulianDay()<<endl;

    bday.invCJD(2443230);
    cout <<"finished"<<endl;
    bday.show();
}
