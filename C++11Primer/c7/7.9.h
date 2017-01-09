#ifndef CPP_PERSON_H
#define CPP_PERSON_H

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
std::istream& read(std::istream &is, Person &p)
{
	is>>p.name>>p.address;
	return is;
}
std::ostream& print(std::ostream &os, const Person &p)
{
	os<<p.name<<" "<<p.address<<std::endl;
	return os;
}

#endif
