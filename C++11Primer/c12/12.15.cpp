#include<memory>
#include<iostream>
struct connection{
	int random;
};
int main()
{
	connection c;
	std::shared_ptr<connection> p(&c, [](connection *c){std::cout<<"disconnected"<<std::endl;}); 
	return 0;
}
