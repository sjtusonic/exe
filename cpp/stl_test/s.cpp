#include <string>
#include <iostream>
#include <list>
#include <algorithm>
using   namespace   std; 

int PrintIt (string& StringToPrint) {
    cout <<StringToPrint <<endl;
}

int main (void) {
    list <string> ms;
    ms.push_back("v0");
    ms.push_back("v1");

    for_each(ms.begin(),ms.end(),PrintIt);
}
