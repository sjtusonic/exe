

struct Employee {
	Employee(int age, std::string name) : age(age), name(name) { } 
	int age;
	std::string name;  // Does not particpate in comparisons
};
bool operator<(const Employee &lhs, const Employee &rhs) ;

int stable_sort();
