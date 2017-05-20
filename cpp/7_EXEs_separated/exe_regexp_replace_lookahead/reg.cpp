#include <iostream>
#include <fstream>
#include <ctime>
#include <regex>

using namespace std;

int main() {
	clock_t start, end;
	start = clock();

	ifstream source("from.ogv", ios::binary);
	ofstream dest("to.ogv", ios::binary);

	std::string line,tmp;
	//dest << source.rdbuf();
	//while(source>>line)
	while(getline(source,line))
	{
		tmp=line;

		std::cout<<"LINE=\t"<<line<<std::endl;

		////////////////////////////////

		std::cout<<"LINE=\t"<<line<<std::endl;
		// PRE ENCODE
		tmp = std::regex_replace(tmp, std::regex("&amp;"), "%HLS_PREENCODE_amp%");
		tmp = std::regex_replace(tmp, std::regex("&lt;" ), "%HLS_PREENCODE_lt%");
		tmp = std::regex_replace(tmp, std::regex("&gt;" ), "%HLS_PREENCODE_gt%");
		tmp = std::regex_replace(tmp, std::regex("<item"     ), "%HLS_PREENCODE_begin_item%");
		tmp = std::regex_replace(tmp, std::regex("><\\\/item>" ), "%HLS_PREENCODE_end_item%"  );
		tmp = std::regex_replace(tmp, std::regex("<annotationInfo>"  ), "%HLS_PREENCODE_begin_anno%");
		tmp = std::regex_replace(tmp, std::regex("<\\\/annotationInfo>"), "%HLS_PREENCODE_end_anno%"  );

		std::cout<<"tmp1=\t"<<tmp<<std::endl;
		// convert
		tmp = std::regex_replace(tmp, std::regex("&"), "&amp;");
		tmp = std::regex_replace(tmp, std::regex("<"), "&lt;");
		tmp = std::regex_replace(tmp, std::regex(">"), "&gt;");

		std::cout<<"tmp2=\t"<<tmp<<std::endl;
		// POST DECODE
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_amp%"), "&amp;");
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_lt%" ), "&lt;" );
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_gt%" ), "&gt;" );
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_begin_item%" ), "<item"    );
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_end_item%"   ), "><\/item>");
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_begin_anno%"), "<annotationInfo>"  );
		tmp = std::regex_replace(tmp, std::regex("%HLS_PREENCODE_end_anno%"  ), "<\/annotationInfo>");


		////////////////////////////////
		std::cout<<"tmp3=\t"<<tmp<<std::endl;
		dest<<tmp<<std::endl;
	}

	source.close();
	dest.close();

	//end = clock();

	//cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	//cout << "CPU-TIME START " << start << "\n";
	//cout << "CPU-TIME END " << end << "\n";
	//cout << "CPU-TIME END - START " <<  end - start << "\n";
	//cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

	return 0;
}
