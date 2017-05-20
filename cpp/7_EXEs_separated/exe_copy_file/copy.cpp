#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    clock_t start, end;
    start = clock();

    ifstream source("from.ogv", ios::binary);
    ofstream dest("to.ogv", ios::binary);

    dest << source.rdbuf();

    source.close();
    dest.close();

    end = clock();

    cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
    cout << "CPU-TIME START " << start << "\n";
    cout << "CPU-TIME END " << end << "\n";
    cout << "CPU-TIME END - START " <<  end - start << "\n";
    cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
