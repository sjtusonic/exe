#ifndef CHARACTER_H_
#define CHARACTER_H_ 
class Point
{
	public:
		Point() {x=0;y=0;};
		Point(int ix,int iy) {x=ix;y=iy;};
		int x;
		int y;
		bool isIn(){return 0;};
};

class Character
{
	public:
		string type; // P pig, W wolf
		Character()
		{
			type="P";
		}
		Character(string t)
		{
			type=t;
		}
		Character(string t,int x,int y)
		{
			type=t;
			setLoc(x,y);
		}
		void setLoc(int ix,int iy) {
			loc.x=ix;
			loc.y=iy;
		};
		Point getLoc(){
			return loc;
		};
		string getType() 
		{
			return type;
		}
		bool isLegal() {}
		Point loc;
};
#endif
