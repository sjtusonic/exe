#ifndef CONTROL_CLASS_H
#define CONTROL_CLASS_H
#include "global.h"
using namespace std;
class Control
{
	public:
#ifdef UNIT_TEST

		void run(){
			while(true){
				char ch;
				cout<<"ch (q to break)=";
				ch=getch();
				cout<<ch<<""<<endl;
				if(ch=='q')
					break;
				if(ch=='r')
				{
					cout<<"REFRESH!"<<""<<endl;
					// call
				}
			}
		};

		/*
			void run(){
// init

// loop
while(true){
char ch;
cout<<"ch (q to break)=";
ch=getch();
cout<<ch<<""<<endl;
if(ch=='q')
break;
if(ch=='r')
{
cout<<"REFRESH!"<<""<<endl;
		// call
		}
		}
		};
		*/;

#else
void run(){
};
#endif
int getch(void) {  

	fcntl( 0, F_SETFL, O_NONBLOCK); // make it non-blocking
	struct termios tm, tm_old;  
	int fd = STDIN_FILENO, c;  
	if(tcgetattr(fd, &tm) < 0)  
		return -1;  
	tm_old = tm;  
	cfmakeraw(&tm);  
	if(tcsetattr(fd, TCSANOW, &tm) < 0)  
		return -1;  
	c = fgetc(stdin);  
	if(tcsetattr(fd, TCSANOW, &tm_old) < 0)  
		return -1;  
	return c;  
}  
Matrix* mat;
Display* display;
private:
int T; // ms
};
#endif
