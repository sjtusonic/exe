#include <vector>
#include <map>
#include <iostream>
#include <assert.h>
using namespace std;

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )


// Catalan number
#define N 6
#define LEN 2



using std::vector;


template <class T>
vector<T> operator+(const vector<T>& lhs, const vector<T>& rhs){	// return type is a vector of integers


	if(lhs.size() != rhs.size()){	// Vectors must be the same size in order to add them!
		throw std::runtime_error("Can't add two vectors of different sizes!");
	}

	vector<T> result;	// Declaring the resulting vector, result

	for(T i=0; i < lhs.size(); i++){	// adding each element of the result vector
		result.push_back(lhs.at(i) + rhs.at(i));	// by adding each element of the two together
	}

	return result;	// returning the vector "result"
}



std::ostream & operator <<(std::ostream &os, 
		const std::map<std::string, std::vector<int>> &m)
{
	for (const auto &p : m)
	{
		os << p.first << ": ";
		for (int x : p.second) os << x << ' ';
		os << std::endl;
	}

	return os;
}
	template <class U, class V>
std::ostream & operator <<(std::ostream &os, 
		const std::map<U, V> &m)
{
	os << "->";
	os << std::endl;
	for (const auto &p : m)
	{
		os << p.first << ": " << p.second;
		os << std::endl;
	}
	os << "<-";

	return os;
}

int main(int argc, char** argv) {

	vector<int> a(3, 3);
	vector<int> b(3, 5);
	vector<int> c = a + b;
	vector<int> check_add;
	check_add.push_back(8);
	check_add.push_back(8);
	check_add.push_back(8);

	PRINT_VECTOR_hor(a);
	PRINT_VECTOR_hor(b);
	PRINT_VECTOR_hor(c);
	if (c == check_add) {
		std::cout<<"operator works for vector!\n";
	}
	else {
		std::cout<<"operator fails for vector!\n";
	}

	std::map<std::string, std::vector<int>> m;
	m["1"]={1};
	m["2"]={2};
	PRINTVAR(m);

	std::map<int, int> m1={{4,4},{6,6}};
	PRINTVAR(m1);
	std::map<int, map<int,int>> m2;
	m2[1]=m1;
	m2[2]=m1;
	PRINTVAR(m2);

	return 0;
}
