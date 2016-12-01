#include "include.top.h"

# if 0
void sort_bubble_wrp () 
{
	cout<<"=============="<<endl;
	PRINT_DEBUG_INFO();
	vector <int> a={6,5,1,2,3,10,2,3,4,5};
	//vector <int> a={6,2,15,3};
	//vector <int> a={6,2};
	PRINT_VECTOR(a);
	cout<<"=============="<<endl;
	vector <int> a_bk=a;
	sort_bubble(a);
	cout<<"=============="<<endl;
	PRINT_VECTOR(a);
	cout<<"=============="<<endl;
	sanity_check(a,a_bk);
}

bool sanity_check(vector<int> &a,vector<int> &a_bk)
{
	cout<<"=============="<<endl;
	cout<<"SANITY CHECK:"<<endl;
	PRINT_VECTOR_hor(a);
	PRINT_VECTOR_hor(a_bk);
	cout<<"=============="<<endl;
	assert(a.size()==a_bk.size());
	for(auto it=a.begin();it!=a.end()-1;it++)
	{
		cout<<"checking-1:"<<(*it)<<""<<endl;
		assert(*it<=*(it+1));
	}
	for(auto it=a.begin();it!=a.end();it++)
	{
		auto t=*it;
		cout<<"checking-2:"<<t<<""<<endl;

		int cnt1=std::count(a.begin(),a.end(),t);
		int cnt2=std::count(a_bk.begin(),a_bk.end(),t);
		PRINTVAR(cnt1);
		PRINTVAR(cnt2);
		assert(cnt1==cnt2);
	}
	cout<<"=============="<<endl;
	cout<<"SANITY CHECK DONE!"<<endl;
	return true;
}


void sort_bubble (vector<int> &arr)
{
	for(auto it=arr.begin()+1;it!=arr.end();it++) 					// n-1+1=n
	{
		cout<<"============================"<<""<<endl;				
		PRINT_VECTOR_hor(arr);
		auto get=*it;					// n
		PRINTVAR(get);
		for(auto it_sorted=it-1;it_sorted!=arr.begin()-1;it_sorted--) // sum(k[i]),  where k[i]=i+1 ,i=1~n
		{
			cout<<"-----"<<""<<endl;
			auto item_sorted=*it_sorted;
			PRINTVAR(item_sorted);

			if(*it_sorted>get )
			{
				*(it_sorted+1)=*it_sorted;
			} 
			else
			{
				*(it_sorted+1)=get;
				break;
			}
			if(it_sorted==arr.begin())
				*(it_sorted)=get;
			PRINT_VECTOR_hor(arr);
		}
		PRINT_VECTOR_hor(arr);
		cout<<"============================"<<""<<endl;
	}
}

#endif
