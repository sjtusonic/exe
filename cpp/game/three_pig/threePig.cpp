//#define SIMPLE_LOG 
#ifdef SIMPLE_LOG
#define DBG 0
#else
#define DBG 1
#endif

#if (DBG)
#define DLOG(x) cout<<#x<<"="<<x<<" @"<<__LINE__<<endl;
#else
#define DLOG(x)
#endif

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#if (DBG)
#define DENTER \
	LVCALL++; PRLVCALL; ::std::cout<<"-->"<<__FUNCTION__<<::std::endl; 
#define DRETURN \
	PRLVCALL; ::std::cout<<"<--"<<__FUNCTION__<<::std::endl; LVCALL--;
#endif

#define DEBUG_MARK PRINT_DEBUG_INFO()
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)
#define DPRINT(x) \
	(::std::cout<<x<<::std::endl   )
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )



#define verbose_PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define verbose_PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define verbose_PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define verbose_PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#ifdef SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)  
#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO()

#define DEBUG_MARK 
#define PRINT_DEBUG_INFO_PREFIX(p)
#define DPRINT(x)
#define PRINT_COUT(p) 

#define DENTER 
#define DRETURN 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <regex>
#include <map>
#include <assert.h>
using namespace std;

#if DBG
static int LV=0;
static int LVCALL=0;
#define PRLV     for(int u12=LV;    u12>0;u12--) {std::cout<<" .. ";}
#define PRLVCALL for(int u12=LVCALL;u12>0;u12--) {std::cout<<" .. ";}
	template <class U>
std::ostream & operator <<(std::ostream &os, const std::vector<U> &m)
{
	os << std::endl;
	PRLV(LV);
	os << "->";
	os << std::endl;
	LV++;
	PRLV(LV);
	for (const auto &p : m)
	{
		os << p << ", " ;
	}
	os << std::endl;
	LV--;
	PRLV(LV);
	os << "<-";

	return os;
}

	template <class U, class V>
std::ostream & operator <<(std::ostream &os, const std::map<U, V> &m)
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
#endif
//=========================================================================================
#include "character.h"
#include "shape.h"
#include "board.h"
int main()
{
	DENTER;
	// init
	Board b,bk;
	bk=b;
	b.showBoardShape();
	b.show();
	// add Character 
	Character* p1=new Character("P",0,1);
	Character* p2=new Character("P",1,1);
	Character* p3=new Character("P",2,2);
	Character* w=new Character("W",3,3);

	b.characterVec.push_back(p1);
	b.characterVec.push_back(p2);
	b.characterVec.push_back(p3);
	b.characterVec.push_back(w);

	b.applyChar();

	// add Shape 
	Shape* s1=new Shape();
	Shape* s2=new Shape({{0,0},{1,0},{1,1}});
	Shape* s3=new Shape({{0,0},{1,0},{2,0},{2,1}});
	s1->name="A";
	//s2->name="B";
	//s3->name="C";

	b.shapeVec.push_back(s1);
	bool r;
	//b.shapeVec.push_back(s2);
	//b.shapeVec.push_back(s3);

	// r=b.applyShape();
	//DLOG(r);

	// final show
	//s1->print();
	//DEBUG_MARK;
	//b.showBoardShape();
	//b.show();
	//DLOG((Point(0,0)==Point(0,1)));
	//DLOG((Point(0,0)==Point(0,0)));
	//DLOG(((*s1)%(*s2)));


# if 1
	for(int i=0;i<b.board.size();i++ )
	{
		auto v1=b.board[i];
		for(int j=0;j<v1.size();j++)
		{
			string s=v1[j];
			DLOG(s);
			if(std::regex_match(s, std::regex("^0.*")))
			{
				continue;
				//DPRINT("INVALID:"<<s);
			}
			//cout<<i<<","<<j<<":"<<s<<"\t";
			s1->setLoc(i,j);
#if 1
			b.resetShape();
			r=b.applyShape();
			DLOG(r);
			//assert(r);
			if(!r)
				continue;
			s1->print();
			DEBUG_MARK;
			b.show();
#endif

			DEBUG_MARK;
#if 1
			s1->r90();
			b.resetShape();
			r=b.applyShape();
			DLOG(r);
			DEBUG_MARK;
			//assert(r);
			if(!r)
				continue;
			DEBUG_MARK;
			s1->print();
			DEBUG_MARK;
			b.show();
#endif
			DEBUG_MARK;
		}
		cout<<""<<""<<endl;
	}
#endif

	//s1->setLoc(3,3);
	//s1->setLoc(0,1);
	//b.resetShape();
	//r=b.applyShape();
	//DLOG(r);
	//assert(r);
	//s1->print();
	//DEBUG_MARK;
	//b.showBoardShape();
	//b.show();
	DRETURN;
	return 1;
}
