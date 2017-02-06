#include <iostream>
using namespace std;
class TEST 
{
	public:
		int* getP(){
			return p;
		};
		void setP(int* n){
			p=n;
		}
		void show() {
			cout<<*p<<endl;
		}
	private:
		int* p;

};

int main() {

	TEST t;
	int i=1234;
	int* n=&i;
	//t.setP(n);
	t.show();
	return 1;
}
