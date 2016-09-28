void f20_2();

template <class T> 
class Stack {
	public:
	Stack();
	~Stack();
	void Push(int n);
	int Pop();
	private:
	int stack[SIZE];
	int tos;
} 
// zjc here
