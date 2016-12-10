// regex_replace example
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <algorithm>
#include <vector>
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

vector<string> parseFuncInfo(string info) ; // info = "func_name({arg1},{arg2},{arg3},...)";  in {...} there can be any characters like [",(){}<>]

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
	s1="method (out brace{br1{br2}} ,br0 {br11{br22}br11} br00, {c},   {d e}    ,  {f})";
	auto r=parseFuncInfo(s1);
	PRINT_VECTOR(r);
}

vector<string> parseFuncInfo(string info)  // info = "func_name({arg1},{arg2},{arg3},...)";  in {...} there can be any characters like [",(){}<>]
{
	string s1=info;
	string s1bk=s1;
	//std::cout<<"BEFORE: "<<s1bk<<std::endl;
	//s1=std::regex_replace(s1,std::regex("\\{[^,]\\}"),"{ }");
	
	std::smatch m;
	string s2;
	string argument_holder;
	while (std::regex_search(s1,m,std::regex("\\{([^,]+)\\}")))
	{
		for (auto &x:m)
		{
			argument_holder=string(x);
			argument_holder=std::regex_replace(argument_holder,std::regex("."),".");
		}
		s2+=m.prefix().str();
		s2+="{"+argument_holder+"}";
		s1=m.suffix().str();
	}
	s2+=s1;
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
	int end=s1bk.find("(");
	final_vector.push_back(s1bk.substr(begin,end-begin));
	auto it=positions.begin();
	//PRINTVAR(s1bk.size());
	//while(end!=s1bk.size())
	while(it!=positions.end())
	{
		begin=end+1;
		end=(*it++);
		string tmp=s1bk.substr(begin,end-begin);
		tmp=std::regex_replace(tmp,std::regex("^\\s+"),"");
		tmp=std::regex_replace(tmp,std::regex("\\s+$"),"");
		final_vector.push_back(tmp);
	}
	begin=end+1;
	end=s1bk.find_last_of(")");
	string tmp=s1bk.substr(begin,end-begin);
	tmp=std::regex_replace(tmp,std::regex("^\\s+"),"");
	final_vector.push_back(tmp);
	//std::cout<<"AFTER : "<<final_vector<<std::endl;
	//std::cout<<"================= "<<std::endl;

	//PRINTVAR(final_vector.size());
	//PRINT_VECTOR(final_vector);
	//std::cout<<"================= "<<std::endl;
	
	return final_vector;
}
