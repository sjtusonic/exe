#include<map>   
#include<string>   
#include<iostream>   

//#include "include.top.h"
#include "map_with_sort.h"

using namespace std;   


typedef pair<string, int> PAIR;   
ostream& operator<<(ostream& out, const PAIR& p) {   
	return out << p.first << "\t << *iter << endl;   " << p.second;   
}   



int map_with_sort_wrp() {    
	//map<string, int> name_score_map;    // here
	map<string, int, is_less<string> > name_score_map;    // here

	name_score_map["LiMin"] = 90;    
	name_score_map["ZiLinMi"] = 79;    
	name_score_map["BoB"] = 92;     
	name_score_map.insert(make_pair("Bing",99));   
	name_score_map.insert(make_pair("Albert",86));    

	for (map<string, int>::iterator iter = name_score_map.begin();   
			iter != name_score_map.end();   
			++iter) {    
		cout<<""<<*iter<<""<<endl;
	}

	foo(name_score_map);
	return 0;
}

void foo(map<string, int, is_less<string> > m) {
}
