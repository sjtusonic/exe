// regex_replace example
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <algorithm>
#include <vector>
#include <assert.h>   

using namespace std;

#define PRINTVAR(a) cout<<#a<<"\t=\t"<<a<<endl;
#define PRINTVAR_hor(a) cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {cout<<u<<":\t"<<*a+u<<endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {cout<<*u<<endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {cout<<*u<<"\t";};cout<<""<<endl;

 #define PRINT_DEBUG_INFO() \
  (::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
//int main ()
//{
//  std::string s ("there is a subsequence in the string\n");
//  std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"
//
//  // using string/c-string (3) version:
//  std::cout << s;
//  std::cout << std::regex_replace (s,e,"sub-$2");
//
//  //// using range/c-string (6) version:
//  //std::string result;
//  //std::regex_replace (std::back_inserter(result), s.begin(), s.end(), e, "$2");
//  //std::cout << result;
//
//  //// with flags:
//  //std::cout << std::regex_replace (s,e,"$1 and $2",std::regex_constants::format_no_copy);
//  //std::cout << std::endl;
//
//std::cout<<"-----------------------------------"<<std::endl;
//  std::string s1 ("func(v1,v2,v3)\n");
//  std::regex e1 (",");   
//
//  std::cout << s1;
//  std::cout << std::regex_replace (s1,e1,",\n\t");
//  return 0;
//}

vector<string> ParseFuncInfo(string info,bool keep_braces=false);  // info = "func_name({arg1},{arg2},{arg3},...)";  in {...} there can be any characters like [",(){}<>]
inline bool isMatchInBrackets (std::string& exp) ;

int main ()
{
	string info("this is an example, 123,456");

	string _str(", \n\t");
	std::cout<<"TEST=================> "<<std::endl;

	std::string s1 ("func(v1,v2,v3)\n");
	std::regex e1 (",");

	std::cout << s1;
	std::cout << std::regex_replace(s1,e1,_str);

//------------------
	_str="";

	std::regex e2 ("\\(.*");

	std::cout << s1;
	std::cout << std::regex_replace(s1,e2,_str);
	std::cout<<"TEST<================= "<<std::endl;

	std::regex e(", ");
	std::regex_match(info,e);
	std::cout<<"BEFORE: "<<info<<std::endl;
	info=std::regex_replace(info,e,_str);
	std::cout<<"AFTER:  "<<info<<std::endl;

	std::cout<<"================= "<<std::endl;

	s1="\"1232\",\"\",\"single quotation\",\"\"double quotations\"\",\"comma,in quotation\",\"str1=\"quote,in,quote\",str2=\"hi, \" is a quotation!\"\"";
	// B        ^    ^                    ^                         ^                      ^                                                           E
	cout<<s1<<endl;
	s1=std::regex_replace(s1,std::regex("ww"),"w");
	//auto it=s1.begin();
	bool flag_quotation=0;
	for(int cntr=0;cntr<s1.size();cntr++)
	{
		//PRINTVAR(flag_quotation);
		//PRINTVAR(cntr);
		auto c=s1[cntr];
		if(c=='"')
			flag_quotation=!flag_quotation;
		if(flag_quotation && c!='"')
			c=' ';
		if(!flag_quotation && c==',')
		{
			s1[cntr]='|';
			//s1.insert(cntr,",@");
			//cntr++;
			//cntr++;
		}
	}
	cout<<s1<<endl;
	std::cout<<"TEST<================= "<<std::endl;

	s1="w w {w} w w";
	std::cout<<"BEFORE: "<<s1<<std::endl;
	s1=std::regex_replace(s1,std::regex("w$"),"\nW");
	PRINT_DEBUG_INFO();
	std::cout<<"AFTER:  "<<s1<<std::endl;
	PRINT_DEBUG_INFO();
	s1=std::regex_replace(s1,std::regex("\\{"),"\n{");
	PRINT_DEBUG_INFO();
	std::cout<<"AFTER:  "<<s1<<std::endl;
	PRINT_DEBUG_INFO();

	std::cout<<"================= "<<std::endl;
	//s1="method (out brace{br1{br2}} ,br0 {br11{br22}br11} br00, {c},   {d e}    ,  {f})a\n";
	s1="method(out brace{br1{br2}} )";
	//s1="method (out brace{br1{br2}} ,\nbr0 {br11{br22}br11} br00, {c},   {d e}    ,  {f})";
	//s1="abcde";
	PRINTVAR(s1);
	auto r=ParseFuncInfo(s1);
	PRINT_VECTOR(r);
	

	string ttt="01234567\nabcde\n//comments\nline4";
	int end=ttt.size()-1;
	PRINTVAR(ttt.size());
	PRINTVAR(ttt.substr(0,3));
	PRINTVAR(ttt.substr(1,3));
	PRINTVAR(ttt.substr(2,3));
	PRINTVAR(ttt.substr(0,end-0));
	PRINTVAR(ttt.substr(1,end-1));
	PRINTVAR(ttt.substr(2,end-2));
	//PRINTVAR(std::regex_replace(ttt,regex("^"),"\n//"));
	//PRINTVAR(std::regex_replace(ttt,regex("\n|^"),"\n//"));
	
	std::cout<<"================= "<<std::endl;
	PRINTVAR(ttt);
	std::cout<<"================= "<<std::endl;
	PRINTVAR(std::regex_replace(ttt,regex("(\n|^)([^/])"),"$1// $2"));
	std::cout<<"================= "<<std::endl;
}

vector<string> ParseFuncInfo(string info,bool keep_braces)  // info = "func_name({arg1},{arg2},{arg3},...)";  in {...} there can be any characters like [",(){}<>]
{
	string info_bk=info;
	//std::cout<<"BEFORE: "<<info_bk<<std::endl;
	//info=std::regex_replace(info,std::regex("\\{[^,]\\}"),"{ }");
	int found=info.find('\n');
	//PRINTVAR(found);
	//PRINTVAR(info.size());
	assert(found==std::string::npos|| found==info.size()-1);
	assert(isMatchInBrackets(info));
	
	std::smatch m;
	string s2;
	string argument_holder;
	while (std::regex_search(info,m,std::regex("\\{([^,]+)\\}")))
	{
		for (auto &x:m)
		{
			argument_holder=string(x);
			argument_holder=std::regex_replace(argument_holder,std::regex("."),".");
		}
		s2+=m.prefix().str();
		s2+="{"+argument_holder+"}";
		info=m.suffix().str();
	}
	s2+=info;
	//std::cout<<"AFTER : "<<s2<<std::endl;


	int pos=s2.find(",");
	vector<int> positions;
	while(pos!=string::npos)
	{
		//PRINTVAR(pos);
		positions.push_back(pos);
		pos=s2.find(",",pos+1);
	}
	//PRINT_VECTOR(positions);
	//std::sort(positions.begin(),positions.end(),std::greater<int>());
	//--------------------------------
	vector<string> final_vector;

	int begin=0;
	int end=info_bk.find("(");
	final_vector.push_back(info_bk.substr(begin,end-begin));
	//auto it=positions.begin();
	//PRINTVAR(info_bk.size());
	//while(end!=info_bk.size())
	
//	while(it!=positions.end())
	for(int cnt=0;cnt!=positions.size()+1;cnt++)
	{
		begin=end+1;
		//end=(*it++);
		if(cnt!=positions.size())
			end=positions[cnt];
		else
			end=info_bk.find_last_of(")");

		string tmp=info_bk.substr(begin,end-begin);
		tmp=std::regex_replace(tmp,std::regex("^\\s+"),"");
		tmp=std::regex_replace(tmp,std::regex("\\s+$"),"");

		if(!keep_braces)
		{
			int end;
			end=tmp.size()-1;
			if(tmp[0]=='{')
				tmp=tmp.substr(1,end);
			end=tmp.size()-1;
			if(tmp[end]=='}')
				tmp=tmp.substr(0,end-1);
		}

		final_vector.push_back(tmp);
	}
	
	return final_vector;
}


inline bool isMatchInBrackets (std::string& exp) 
{
	string pStack;
	for(int i=0;i<exp.size();i++)
	{
		if(
				exp[i]=='[' ||
				exp[i]=='{' ||
				exp[i]=='(' 
		  )
			pStack.push_back(exp[i]);
		if(
				exp[i]==']' ||
				exp[i]=='}' ||
				exp[i]==')' 
		  )
		{
			char c=pStack[pStack.size()-1];
			pStack.pop_back();
			if(c=='\a')
				return false; // if the expression has only closing brackets
			else if(
					c=='['&&exp[i]==']' ||
					c=='{'&&exp[i]=='}' ||
					c=='('&&exp[i]==')' 
					)
			{
			}
			else 
				return false; // if mismatch

		}

	}
	if(!pStack.empty())
		return false; // if the expression has only opening brackets
	else
		return true;
}
