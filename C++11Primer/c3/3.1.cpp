#include<iostream>
#include<string>
#include "Sales_data.h"
int main()
{
	using std::cout; 
	using std::cin;
	using std::endl;
	//ex 1.20
	cout<<"1.20"<<endl;
	Sales_data s1, s2;
	while(cin>>s1.bookNo>>s1.units_sold>>s1.revenue)
	{
		cout<<s1.bookNo<<" "<<s1.units_sold<<" "
		    <<s1.revenue+s2.revenue;
	}
	
	return 0;
}
