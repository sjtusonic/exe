class Employee_class {
public:
	Employee_class(int age, std::string name) : age(age), name(name) { } 

	Employee_class& operator+=(const int age)
	{
		this->age=this->age+1;
		return *this;
	}
	Employee_class& operator+=(const Employee_class & rhs)
	{
		this->age=this->age+rhs.age;
		return *this;
	}
	Employee_class& operator++()
	{
		this->age++;
		return *this;
	}

	bool operator< (const Employee_class & rhs) { return this->getAge() < rhs.getAge(); }
	bool operator> (const Employee_class & rhs) { return this->getAge() > rhs.getAge(); }
	bool operator<=(const Employee_class & rhs) { return !(*this>rhs); }
	bool operator>=(const Employee_class & rhs) { return !(*this<rhs); }

	int getAge() 				const {return age; }
	std::string getName() 	const {return name;}

private:
	int age;
	std::string name;  // Does not particpate in comparisons
};

void exe_operator ();
