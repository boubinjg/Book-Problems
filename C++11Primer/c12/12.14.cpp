#include<memory>
#include<iostream>
struct connection{
	int random;
};
void disconnect(connection *c)
{
	std::cout<<"disconnected"<<std::endl;
}
void destruct(connection *c)
{
	disconnect(c);
}
int main()
{
	connection c;
	std::shared_ptr<connection> p(&c, destruct); 
	return 0;
}
