#include<bitset>
#include<iostream>
template <long int T>
class directAddressTable{
public:
	directAddressTable(){

	}
	void set(int val){
		bits.set(val, 1);
	}
	bool get(int val){
		return bits[val];
	}
	void deleteItem(int val){
		bits.set(val, 0);
	}
private:
	std::bitset<T> bits;
};
int main()
{
	directAddressTable<64> b;
	b.set(1);
	std::cout<<b.get(1)<<std::endl;
	std::cout<<b.get(55)<<std::endl;
	return 0;
}
