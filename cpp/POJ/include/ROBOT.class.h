#include "lib.h"
#include "MATRIX.class.h"
class ROBOT
{
	public:
		ROBOT(Point<int> l,string h){loc=l;head=h;};
		void setLoc(Point<int> l) {loc=l;};
		Point<int> getLoc() {return loc;};
		void setHead(string h) {head=h;};
		string getHead() {return head;};
		void setBoard(MATRIX<int>* p){board=p;};
		MATRIX<int>* getBoard() {return board;};

		void run(){
			for(auto i:instTable)
			{
				PRINTVAR(i);
			}
		};
		void exe(string cmd) {
			string towards=split(cmd," ")[0];
			int multiply  =stoi(split(cmd," ")[1]);
			PRINTVAR(towards);
			PRINTVAR(multiply);
			if(towards=="F")
				moveFoward(multiply);
			else
				turn(towards,multiply);
		};
		void turn(string to) {
			if(head == "N")
			{
				if(to == "L" ) head="W";
				if(to == "R" ) head="E";
			}
			if(head == "E")
			{
				if(to == "L" ) head="N";
				if(to == "R" ) head="S";
			}
			if(head == "W")
			{
				if(to == "L" ) head="S";
				if(to == "R" ) head="N";
			}
			if(head == "S")
			{
				if(to == "L" ) head="E";
				if(to == "R" ) head="W";
			}
		};
		void turn(string to,int mult) {
			for(int i=0;i<mult;i++)
				turn(to);
		};
		bool moveFoward() {
			if(head == "N") loc.incrY();
			if(head == "E") loc.incrX();
			if(head == "W") loc.decrX();
			if(head == "S") loc.decrY();
			PRINT_DEBUG_INFO();
			if(!getBoard()->isOnEdge(getLoc().getX(),getLoc().getY()))
			{
			PRINT_DEBUG_INFO();
				return false;
			}
			else
			{
				return true;
			}
		};
		bool moveFoward(int mult) {
			for(int i=0;i<mult;i++)
				if(!moveFoward())
					return false;
			return true;
		};
		void addInst(string inst) {
			instTable.push_back(inst);
		};
		void show() {
			cout<<"ROBOT is in:\t";
			loc.show();
			board->show(getLoc().getY(),getLoc().getX(),"R");
			cout<<"\thead to\t"
			<<head
			<<"\nInstructions:\t"
			<<endl;
			for(auto i:instTable)
			{
				cout<<i<<endl;
			}
		};
	private:
		vector<string> instTable;
		Point<int> loc;
		string head;
		MATRIX<int>* board;
};
