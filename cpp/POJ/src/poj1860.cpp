#include "include.top.h"
#include "gnuplot_i.h"
#include "poj1860.h"
#include "GRAPH.class.h"
#include "GRAPH.class.cpp"

#include <math.h>

#include <iomanip>
#include <map>
#include <regex>


#include <fstream>
using namespace std;

void f(string* node);
void poj1860 () 
{
#if 1
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1860"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1860.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";
	//----------------------------------------------------------
	string filename_out="output/poj1860.out";
	// clean the file "output/poj1860.out"
	std::ofstream outfile_init(filename_out);
	outfile_init.close();
	std::ofstream outfile(filename_out,ios::app);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";
	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	string line;

	//Edge <double>null_edge(-1,1);
	Edge <double>null_edge(-1,1,0,0);
	int cnt_line=0;
	int num_of_currency,num_of_points,kind_of_Nick_has;
	double qty_of_Nick_has;
	double rab,cab,rba,cba;

	GRAPH<string,double>* graph_currency_ptr;
	while(getline(infile,line))
	{
		if (std::regex_match(line, std::regex("^//.*") )) // lines begin with "//"
			continue;

		if (std::regex_match(line, std::regex("^\\s*$") )) // blank lines
			continue;

		cnt_line++;
		cout<<"-------------------------------------"<<endl;
		cout<<"LINE="<<line<<endl;
		if(cnt_line==1)
		{
			stringstream ssin(line);
			ssin>>num_of_currency>>num_of_points>>kind_of_Nick_has>>qty_of_Nick_has;
			PRINTVAR(num_of_currency);
			PRINTVAR(num_of_points);
			PRINTVAR(kind_of_Nick_has);
			PRINTVAR(qty_of_Nick_has);
			//GRAPH<string,double> graph_currency=new GRAPH<string,double>(num_of_currency,null_edge);
			//graph_currency_ptr=&graph_currency;
			graph_currency_ptr=new GRAPH<string,double>(num_of_currency,null_edge);

		}
		if(cnt_line>1 && cnt_line<num_of_points+2)
		{
			cout<<"Point:"<<endl;
			PRINTVAR(line);
			// integer A and B - numbers of currencies it exchanges,// real RAB, CAB, RBA and CBA - exchange rates and commissions when exchanging A to B and B to A respectively
			//
			string* pA=new string;
			string* pB=new string;
			stringstream ssin(line);
			ssin>>*pA>>*pB>>rab>>cab>>rba>>cba;
			Edge<double> tmpEdgeAB(1,true,rab,cab);
			Edge<double> tmpEdgeBA(1,true,rba,cba);
			PRINT_DEBUG_INFO();
			graph_currency_ptr->addEdge(pA,pB,tmpEdgeAB);
			PRINT_DEBUG_INFO();
			graph_currency_ptr->addEdge(pB,pA,tmpEdgeBA);
			PRINT_DEBUG_INFO();

		}
	}
	cout<<"-----------------------------------------------"<<endl;
	cout<<"SHOW"<<endl;
	graph_currency_ptr->show();


	cout<<"-----------------------------------------------"<<endl;
	//graph_currency_ptr->getParentIdList(1);
	//graph_currency_ptr->getChildIdList(1);
	//graph_currency_ptr->traverseDFS(graph_currency_ptr->getNodeById(0));

#if 0
	//----------------------------------------------------------
	// traverseBFS
	cout<<"traverseBFS:"<<endl;
	graph_currency_ptr->traverseBFS(graph_currency_ptr->getNodeById(3),f);
	std::cout << "id2BFSdepth:" << " \n";
	graph_currency_ptr->showMAP_id2BFSdepth();
	std::cout << "printBFSTree:" << " \n";
	graph_currency_ptr->printBFSTree();
	//----------------------------------------------------------
	cout<<"traverseBFS:"<<endl;
	graph_currency_ptr->traverseBFS(graph_currency_ptr->getNodeById(2),f);
	std::cout << "id2BFSdepth:" << " \n";
	graph_currency_ptr->showMAP_id2BFSdepth();
	std::cout << "printBFSTree:" << " \n";
	graph_currency_ptr->printBFSTree();
	//----------------------------------------------------------
	cout<<"traverseBFS:"<<endl;
	graph_currency_ptr->traverseBFS(graph_currency_ptr->getNodeById(1),f);
	std::cout << "id2BFSdepth:" << " \n";
	graph_currency_ptr->showMAP_id2BFSdepth();
	std::cout << "id2BFSparent:" << " \n";
	graph_currency_ptr->showMAP_id2BFSparent();
	std::cout << "printBFSTree:" << " \n";
	graph_currency_ptr->printBFSTree();
	std::cout << "------------------" << " \n";
	std::cout << "printShortestPath:" << " \n";
	std::cout << "------------------" << " \n";
	graph_currency_ptr->printShortestPath(1,5);
	std::cout << "------------------" << " \n";
	graph_currency_ptr->printShortestPath(5,1);
	std::cout << "------------------" << " \n";
	//----------------------------------------------------------
#endif
#if 1
	//----------------------------------------------------------
	// traverseDFS
	cout<<"traverseDFS:"<<endl;
	graph_currency_ptr->traverseDFS(graph_currency_ptr->getNodeById(3),f);
	//----------------------------------------------------------
	cout<<"-----------------------------------------------"<<endl;
	cout<<"print DFS time:"<<endl;
	cout<<"TIME"<<"\t:\t"<<"NODE COLOR"<<endl;
	for(int i=0;i<100;i++)
	{
		for(int id=0;id<100;id++)
		{
			auto MAP_grey=graph_currency_ptr->MAP_id2DFSdepth_grey;
			auto MAP_black=graph_currency_ptr->MAP_id2DFSdepth_black;
			if(MAP_grey.count(id) && MAP_grey[id]==i)
				cout<<i<<"\t:\t"<<id<<"\tgrey \t"<<endl;
			if(MAP_black.count(id) &&MAP_black[id]==i)
				cout<<i<<"\t:\t"<<id<<"\tblack\t"<<endl;
		}
	}
	cout<<"-----------------------------------------------"<<endl;
	//----------------------------------------------------------
	//----------------------------------------------------------
#endif
	//----------------------------------------------------------
	// dump output file
	outfile<<"====================="<<endl;
	//----------------------------------------------------------

	//Edge <double>null_edge;
	/////////////////////////////////


	// PRINT_DEBUG_INFO();
	// auto m=graph_currency.getMat();
	// PRINTVAR(m.size());
	// PRINT_DEBUG_INFO();
	// graph_currency.show();
	// PRINT_DEBUG_INFO();
	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
	outfile.close();


#endif
}

void f(string* node)
{
	cout<<"do for node:"<<*node<<"\t@"<<node<<endl;
}

