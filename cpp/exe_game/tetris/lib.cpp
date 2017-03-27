
#include "global.h"


//static void sleep_ms(unsigned int secs)
void sleep_ms(unsigned int secs)
{

    struct timeval tval;

    tval.tv_sec=secs/1000;

    tval.tv_usec=(secs*1000)%1000000;

    select(0,NULL,NULL,NULL,&tval);

}

void deleteFromVectorShape(vector<Shape*>* vecPtr, Shape* item)
{
	PRINT_DEBUG_INFO_PREFIX("deleteFromVectorShape");
	auto vec=*vecPtr;
	int size=vec.size();
	PRINTVAR(vec.size());
	int cntr=0;
	for (auto iter=vecPtr->begin();iter!=vecPtr->end();)
	{
		Shape* t=*iter; // t is Shape*
		//int ind=t.transformIsCombined(unit_transforms_wo_zeros);
		if (t==item)
		{
			//cout<<"erase Shape: ("<<item->x<<","<<item->y<<")"<<endl;
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
	PRINTVAR(vec.size());
}
