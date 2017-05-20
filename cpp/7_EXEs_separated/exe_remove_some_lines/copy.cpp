#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
	clock_t start, end;
	start = clock();

	ifstream source("from.ogv", ios::binary);
	ofstream dest("to.ogv", ios::binary);

	std::string line;
	//dest << source.rdbuf();
	//while(source>>line)
	std::string head= "<annotationInfo>";
	std::string tail= "</annotationInfo>";
	dest<<head<<std::endl;
	while(getline(source,line))
	{
		std::cout<<"LINE=\t"<<line<<std::endl;
		if(
				line== head
				|| line== tail
		  )
			continue;
		dest<<line<<std::endl;
	}
	dest<<tail<<std::endl;

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
