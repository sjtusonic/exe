
#include <chrono>

//using namespace std;
//using namespace std::chrono;
#include "include.top.h"

void sort_insert_wrp () 
{


	cout<<"=============="<<endl;
	PRINT_DEBUG_INFO();
	vector <int> a={6,5,1,2,3,10,2,3,4,5};
	//vector <int> a={6,2,15,3};
	//vector <int> a={6,2};
	PRINT_VECTOR(a);
	cout<<"=============="<<endl;
	vector <int> a_bk=a;
	chrono::high_resolution_clock::time_point t1 =  chrono::high_resolution_clock::now();
	sort_insert(a);
	//sort_insert2(a);
	chrono::high_resolution_clock::time_point t2 =  chrono::high_resolution_clock::now();
	cout<<"=============="<<endl;
	PRINT_VECTOR(a);
	cout<<"=============="<<endl;
	sanity_check(a,a_bk);

	auto duration =  chrono::duration_cast< chrono::microseconds>( t2 - t1 ).count();
	cout<<"duration:"<<duration<<endl;
}

bool sanity_check(vector<int> &a,vector<int> &a_bk)
{
	cout<<"=============="<<endl;
	cout<<"SANITY CHECK:"<<endl;
	cout<<"before:\t";
	PRINT_VECTOR_hor(a_bk);
	cout<<"after:\t";
	PRINT_VECTOR_hor(a);
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

void sort_insert(vector<int> &arr) // this version is the same as MIT web course
{
	for(auto it=arr.begin()+1;it!=arr.end();it++) 					// n-1+1=n
	{
		cout<<"============================"<<""<<endl;				
		PRINT_VECTOR_hor(arr);
		auto get=*it;					// n
		PRINTVAR(get);
		auto it_sorted=it-1;
		while(it_sorted!=arr.begin()-1 && *it_sorted>get) // sum(k[i]),  where k[i]=i+1 ,i=1~n
		{
			cout<<"-----"<<""<<endl;
			PRINTVAR(*it_sorted);
			*(it_sorted+1)=*it_sorted;
			PRINT_VECTOR_hor(arr);
			it_sorted--;
		}
		*(it_sorted+1)=get;
		PRINT_VECTOR_hor(arr);
		cout<<"============================"<<""<<endl;
	}
}

void sort_insert_zjc (vector<int> &arr) // this version is like the MIT web course
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

void sort_insert2 (vector<int> &arr)
{
	for(auto it=arr.begin()+1;it!=arr.end();it++)
	{
		cout<<"============================"<<""<<endl;
		PRINT_VECTOR_hor(arr);
		auto get=*it;
		PRINTVAR(get);
		for(auto it_sorted=arr.begin();it_sorted!=it+1;it_sorted++)
		{
			cout<<"-----"<<""<<endl;
			auto item_sorted=*it_sorted;
			PRINTVAR(item_sorted);

			if(*it_sorted>get )
			{
				cout<<"swap:"<<get<<","<<*it_sorted<<endl;
				int& ref=(*it_sorted);
				swap(get,ref);
			} 
			if (it_sorted==it)
				*(it_sorted)=get;
			PRINT_VECTOR_hor(arr);
		}
		PRINT_VECTOR_hor(arr);
		cout<<"============================"<<""<<endl;
	}
}
void swap(int& a,int& b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void swap(int* a,int* b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
