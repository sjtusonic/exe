#include <vector>
#include "include.top.h"
using namespace std;
using std::string;
using std::vector;

template <class T>
void print_vector(vector<T> v) {
	std::cout<<"get vector "<<""<<std::endl;
	cout<<"size="<<v.size()<<""<<endl;
	for(auto& c:v)
	{
		cout<<"\t"<<c<<""<<endl;
	}
}

void f_3_20_redo () {
	cout<<"---------"<<""<<endl;
	cout<<"redo exe3.20:"<<""<<endl;
	cout<<"---------"<<""<<endl;

	vector<int> vec_int_3_21;
#if 0
	int buf_num;
	while(cin>>buf_num)
	{
		PRINTVAR(buf_num);
		vec_int_3_21.push_back(buf_num);
	}
#else
	vec_int_3_21.push_back(1);
	vec_int_3_21.push_back(4);
	vec_int_3_21.push_back(2);
	vec_int_3_21.push_back(33);
	vec_int_3_21.push_back(6);
	vec_int_3_21.push_back(7);
	vec_int_3_21.push_back(17);
#endif
	int sum=0;
	cout<<"print_vector(vec_int_3_21): "<<""<<endl;
	print_vector(vec_int_3_21);
	cout<<"1. calc sum of neighbour:"<<""<<endl;
	for(auto it =vec_int_3_21.cbegin();it!=vec_int_3_21.cend();it++)
	{
		auto i=*it;
		auto i_bk=*(it-1);
		if(it!=vec_int_3_21.cbegin())
		{
			sum=i+i_bk;
			cout<<"sum="<<sum<<""<<endl;
		}
	}

	cout<<"2. calc sum of [0]+[end],[1]+[end-1], etc. :"<<""<<endl;
	decltype(vec_int_3_21.size()) cntr_i=0,cntr_j=0,size;
	size=vec_int_3_21.size();
	PRINTVAR(size);
	auto it1=vec_int_3_21.cbegin();
	auto it2=vec_int_3_21.cend()-1;
	//while(it1!=it2 && it1!=it2+1)
	while(it1<it2 )
	{
		sum=(*it1)+(*it2);
		cout<<"sum="<<sum<<"="<<(*it1)<<"+"<<*it2<<endl;
		it1++;
		it2--;
	}
	return;
}

void exe_3_16() {
	cout<<"==============="<<endl;
	cout<<"exe_3_13 & exe_3_16:"<<""<<endl;
	cout<<"==============="<<endl;
	vector<int> v0(5,3);
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};

	cout<<"v0"<<""<<endl;
	print_vector(v0);
	cout<<"v1"<<""<<endl;
	print_vector(v1);
	cout<<"v2"<<""<<endl;
	print_vector(v2);
	cout<<"v3"<<""<<endl;
	print_vector(v3);
	cout<<"v4"<<""<<endl;
	print_vector(v4);
	cout<<"v5"<<""<<endl;
	print_vector(v5);
	cout<<"v6"<<""<<endl;
	print_vector(v6);
	cout<<"v7"<<""<<endl;
	print_vector(v7);
	//PRINTVAR(v7);
	//
	cout<<"==============="<<endl;
	cout<<"exe_3_17:"<<""<<endl;
	cout<<"==============="<<endl;
	vector<string> vec_word;
#if 0
	string buf;
	while(cin>>buf)
	{
		PRINTVAR(buf);
		vec_word.push_back(buf);
	}
#else
	vec_word.push_back("a");
	vec_word.push_back("b?");
	vec_word.push_back("d1");
	vec_word.push_back("sdsaf!!");
#endif
	cout<<"print_vector(vec_word):"<<""<<endl;
	print_vector(vec_word);

	for(auto &w:vec_word)
	{
		w=stringToUpper(w);
		cout<<"w="<<w<<""<<endl;
	}
	cout<<"print_vector(vec_word):"<<""<<endl;
	print_vector(vec_word);
	cout<<"==============="<<endl;
	cout<<"exe_3_19:"<<""<<endl;
	cout<<"==============="<<endl;
	vector<int> v3_19_0(10,42);
	vector<int> v3_19_1{42,42,42,42,42,42,42,42,42,42};
	vector<int> v3_19_2={42,42,42,42,42,42,42,42,42,42};
	vector<int> v3_19_3;
	for(auto i:string(10,'x'))
	{
		PRINTVAR(i);
		v3_19_3.push_back(42);
	}
	print_vector(v3_19_0);
	print_vector(v3_19_1);
	print_vector(v3_19_2);
	print_vector(v3_19_3);
	cout<<"==============="<<endl;
	cout<<"exe_3_20:"<<""<<endl;
	cout<<"==============="<<endl;
	vector<int> vec_int;
#if 0
	int buf_num;
	while(cin>>buf_num)
	{
		PRINTVAR(buf_num);
		vec_int.push_back(buf_num);
	}
#else
	vec_int.push_back(1);
	vec_int.push_back(4);
	vec_int.push_back(2);
	vec_int.push_back(33);
	vec_int.push_back(6);
	vec_int.push_back(7);
#endif
	int sum=0;
	int cntr=0;
	int i_bk;
	cout<<"print_vector(vec_int): "<<""<<endl;
	print_vector(vec_int);
	cout<<"1. calc sum of neighbour:"<<""<<endl;
	for(auto i : vec_int)
	{
		if(cntr!=0)
		{
			sum=i+i_bk;
			cout<<"sum="<<sum<<""<<endl;
		}
		cntr++;
		i_bk=i;
	}
	cout<<"2. calc sum of [0]+[end],[1]+[end-1], etc. :"<<""<<endl;
	decltype(vec_int.size()) cntr_i=0,cntr_j=0,size;
	size=vec_int.size();
	PRINTVAR(size);
	for(auto i : vec_int)
	{
		if(cntr_i>=size/2){break;}
		cntr_j=0;
		for(auto j : vec_int)
		{
			//PRINTVAR(cntr_i);
			//PRINTVAR(cntr_j);
			if((cntr_j+cntr_i)==vec_int.size()-1) {
				sum=i+j;
				cout<<"sum("<<cntr_i<<"+"<<cntr_j<<") ="<<sum<<endl;
			}
			cntr_j++;
		}
		cntr_i++;
	}
	cout<<"==============="<<endl;
	cout<<"exe_3_21, redo exe:"<<""<<endl;
	cout<<"==============="<<endl;
	cout<<"---------"<<""<<endl;
	cout<<"redo exe3.17:"<<""<<endl;
	cout<<"---------"<<""<<endl;
	vector<string> vec_word_3_21;
#if 0
	string buf;
	while(cin>>buf)
	{
		PRINTVAR(buf);
		vec_word_3_21.push_back(buf);
	}
#else
	vec_word_3_21.push_back("a");
	vec_word_3_21.push_back("b?");
	vec_word_3_21.push_back("d1");
	vec_word_3_21.push_back("sdsaf!!");
#endif
	cout<<"print_vector(vec_word_3_21):"<<""<<endl;
	print_vector(vec_word_3_21);

	for(auto it=vec_word_3_21.begin();it!=vec_word_3_21.end();it++)
	{
		(*it)=stringToUpper(*it);
		//cout<<"*it="<<*it<<""<<endl;
	}
	cout<<"print_vector(vec_word_3_21):"<<""<<endl;
	print_vector(vec_word_3_21);

	f_3_20_redo();


}
