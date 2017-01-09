#ifndef CPP_PERSON_H
#define CPP_PERSON_H

#include<iostream>
#include<string>
//getName and getAddr should be const as they should not modify their return values
struct Person{
	std::string name, address;
	std::string getName() const { return name; }
	std::string getAddr() const { return address; }
	Person() = default;
	Person(std::string n, std::string a) 
	: name(n), address(a) {}
	Person(std::istream &is);
};
std::istream& read(std::istream &is, Person &p)
{
	is>>p.name>>p.address;
	return is;
}
Person::Person(std::istream &is)
{
	read(is, *this);
}
std::ostream& print(std::ostream &os, const Person &p)
{
	os<<p.name<<" "<<p.address<<std::endl;
	return os;
}

#endif
