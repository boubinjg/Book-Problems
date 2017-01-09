#include<iostream>
#include<string>
//getName and getAddr should be const as they should not modify their return values
struct Person{
	std::string name, address;
	std::string getName() const
	{
		return name;
	}
	std::string getAddr() const
	{
		return address;
	}
};
int main()
{
	Person p;
	Person cp;
	p.name = "a";
	p.address = "addr";
	
	std::cout<<p.getName()<<" "<<p.getAddr()<<std::endl;
	std::cout<<cp.getName()<<" "<<cp.getAddr()<<std::endl;
	
	return 0;
}
