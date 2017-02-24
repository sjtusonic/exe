#ifndef SHAPE_EXIST_CLASS_H
#define SHAPE_EXIST_CLASS_H
class ShapeExist: public Shape 
{
	public:
		ShapeExist(int w_board,int h_board)
		{
			type=999;
			ori="NA";
			ul_row=0;
			ul_col=0;
		}
		void merge(Shape * shape); // merge the new added shape, after the shape doesn't move
		void checkDeleteRow(); // then check whether to delete a row or not
		void update(); // update all location after deleting
		vector<string> touch(Shape* shape);
		// "NOT": not touch
		// "HIT": mean one shape hit into another 
		// S:
		// E:
		// N:
		// W:
}
#endif
