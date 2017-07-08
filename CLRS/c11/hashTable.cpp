#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<utility>
#include<memory>
//very basic hash table that uses double hashing for string keys.
template <typename T>
class HashTable{
public:
	HashTable(){
		size = 701;
		table = std::vector<std::shared_ptr<std::pair<std::string, T>>>(701);
	}
	void insert(const std::string& key, T val){
		int i = 1;
		int h;
		while(table[h = hash(key, i)] != nullptr && table[h]->first != key){
			i++;
		}
		if(table[h] == nullptr)
			table[h] = std::make_shared<std::pair<std::string, T>>(std::make_pair(key, val));	
		else
			table[h]->second = val;
	}
	T find(const std::string& key){
		int i = 1;
		int h;
		while(table[h = hash(key, i)] != nullptr && table[h]->first != key){
			i++;
		}
		if(table[h] == nullptr){
			return -1;
		}
		return table[h]->second;
	}
	void remove(const std::string& key){
		int i = 1;
		int h;
		while(table[h = hash(key, i)] != nullptr && table[h]->first != key){
			i++;
		}	
		if(table[h] != nullptr){
			table[h] = nullptr;
		}
	}	
private:
	size_t hash(const std::string& key, int attempt){
		long long strVal = 0;
		int radix = 128;
		for(auto i = key.rbegin(); i != key.rend(); i++){
			strVal += pow(radix, i - key.rbegin()) * (int)(*i);
		}
		size_t hash1 = strVal % size;
		size_t hash2 = 1 + (strVal % (size-1));
		return (hash1 + attempt*hash2) % size;
	}
	size_t size;
	std::vector<std::shared_ptr<std::pair<std::string,T>>> table;
};
int main()
{
	HashTable<int> t;
	t.insert(std::string("abcd"), 10);
	std::cout<<t.find("abcd")<<std::endl;
	t.insert(std::string("abcd"), 11);
	std::cout<<t.find("abcd")<<std::endl;
	t.remove("abcd");
	std::cout<<t.find("abcd")<<std::endl;
	return 0;
}
