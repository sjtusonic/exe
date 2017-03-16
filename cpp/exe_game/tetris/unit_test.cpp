#include "unit_test.h"

void test_Control() { // FUNC
	// test control
	cout<<"==================="<<""<<endl;
	cout<<"TEST CLASS: Constrol"<<""<<endl;
	cout<<"==================="<<""<<endl;
	Control c; c.run();
	cout<<"==================="<<""<<endl;

}
void test_Matrix() // FUNC
{
	cout<<"==================="<<""<<endl;
	cout<<"TEST CLASS: Matrix"<<""<<endl;
	cout<<"==================="<<""<<endl;
	int WIDTH=10;
	int HEIGHT=5;
	//
	Display* d=new Display();
	d->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	d->show();
	//
	cout<<"==================="<<""<<endl;
}
void test_flow() // FUNC
{
	// INIT:
	int WIDTH=10;
	int HEIGHT=10;
	//
	Display* display=new Display();
	display->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	display->m=m;
	display->show();

	Control controller; 

	// LOOP:
	while(true)
	{
		char ch;
		cout<<"ch (q to break)=";
		ch=controller.getch();
		cout<<ch<<""<<endl;
		if(ch=='q')
			break;
		if(ch=='o')// add new shape
		{
			cout<<"ADD NEW SHAPE!"<<""<<endl;
			Shape* shape=new Shape(WIDTH,HEIGHT);
			//Shape* shape=new Shape(WIDTH,HEIGHT,5);
			shape->init();
			shape->update();
			m->addShape(shape);
			m->update();

		}
		if(ch=='r') // will instead by timing-triggered
		{
			cout<<"REFRESH!"<<""<<endl;
			// REFRESH Matrix
			display->show();
			cout<<"TICK!"<<""<<endl;
			m->tick();
			cout<<"UPDATE!"<<""<<endl;
			m->update();
			// Display
			display->show();
			// call
		}
		if(ch=='p') // for debug
		{
			cout<<"UPDATE!"<<""<<endl;
			m->update();
			// Display
			display->show();
		}
		Shape* shape=m->getShape();
		if(	ch=='s')
			shape->move("S");
		if(	ch=='a')
			shape->move("W");
		if(	ch=='d')
			shape->move("E");
		if(	ch=='w')
			shape->turn("left");
		if(	ch=='e')
			shape->turn("right");
	}
}
void test_flow_tick() // FUNC
{
	// INIT:
	int WIDTH=10;
	int HEIGHT=10;
	//
	Display* display=new Display();
	display->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	display->m=m;
	display->show();

	Control controller; 

	// LOOP:
	while(true)
	{
		char ch;
		cout<<"ch (q to break)=";
		ch=controller.getch();
		cout<<ch<<""<<endl;

		int T=1;
		sleep(T);

		if(ch=='q')
			break;
		if(ch=='o')// add new shape
		{
			cout<<"ADD NEW SHAPE!"<<""<<endl;
			Shape* shape=new Shape(WIDTH,HEIGHT);
			//Shape* shape=new Shape(WIDTH,HEIGHT,5);
			shape->init();
			shape->update();
			m->addShape(shape);
			m->update();

		}
		if(ch=='r') // will instead by timing-triggered
		{
			cout<<"REFRESH!"<<""<<endl;
			// REFRESH Matrix
			display->show();
			cout<<"TICK!"<<""<<endl;
			m->tick();
			cout<<"UPDATE!"<<""<<endl;
			m->update();
			// Display
			display->show();
			// call
		}
		if(ch=='p') // for debug
		{
			cout<<"UPDATE!"<<""<<endl;
			m->update();
			// Display
			display->show();
		}
		Shape* shape=m->getShape();
		if(	ch=='s')
			shape->move("S");
		if(	ch=='a')
			shape->move("W");
		if(	ch=='d')
			shape->move("E");
		if(	ch=='w')
			shape->turn("left");
		if(	ch=='e')
			shape->turn("right");
	}
}
void test_Point() // FUNC
{
	vector<Point> vp;
	vp.push_back(Point(0,0));
	vp.push_back(Point(0,1));
	vp.push_back(Point(0,2));
	PRINT_VECTOR(vp);
	cout<<"------------------"<<""<<endl;
	for(auto p:vp)
	{
		PRINTVAR(p);
		p.x++;
		PRINTVAR(p);
	}
}
void test_deleteFromVector() // FUNC
{
	vector<Point*> v;
	v.push_back(new Point(0,0));
	v.push_back(new Point(0,1));
	v.push_back(new Point(0,2));
	//PRINT_VECTOR_hor(v);
	cout<<"--------"<<""<<endl;
	for(auto p:v)
		cout<<""<<*p<<"\t@"<<p<<endl;
	for(Point* p:v)
	{
		if(p->x==0&& p->y==1)
			deleteFromVector(&v,p);
	}
	cout<<"--------"<<""<<endl;
	for(auto p:v)
		cout<<""<<*p<<"\t@"<<p<<endl;
	//PRINT_VECTOR_hor(v);
}
void test_time_engine()
{
	int cnt=0;
	while(true)
	{
		int T=1;// seconds
		cout<<"cnt="<<cnt<<""<<endl;
		sleep(T);
		cnt++;
	}
}
void deleteFromVector(vector<Point*>* vecPtr, Point* item) // FUNC
{
	auto vec=*vecPtr;
	int size=vec.size();
	int cntr=0;
	for (auto iter=vecPtr->begin();iter!=vecPtr->end();)
	{
		Point* t=*iter; // t is Point*
		//int ind=t.transformIsCombined(unit_transforms_wo_zeros);
		if (t==item)
		{
			//cout<<"erase:"<<endl;
			//vec.erase(iter); // delete the combined transform
			vecPtr->erase(iter);
			size=vecPtr->size();
		}
		else 
		{
			iter++;
		}
		cntr++;
	}
}
