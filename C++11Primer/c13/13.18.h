#include<string>
class Employee{
private:
	static unsigned id;	
	unsigned uniqueId;
	std::string name;
	
public:
	Employee() = default;
	Employee(std::string s){ name = s; uniqueId = ++id; }
	unsigned getId() { return uniqueId; }
};
unsigned Employee::id = 0;
