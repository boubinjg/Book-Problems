#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
int main()
{
	std::string s = "asdf1234asdf545", s2 = "aaaaaaaaaaaaaa", s3 = "1111111111111";
	
	auto isdigit = [](char c){return std::isdigit(c);};

	//determines whether the range is partitioned based on the predicate
	bool b = std::is_partitioned(s.begin(), s.end(), isdigit);
	std::cout<<std::boolalpha<<b<<std::endl;
	
	//copies the partitions from s to s2 and s3
	std::partition_copy(s.begin(), s.end(), s2.begin(), s3.begin(), isdigit);
	std::cout<<s2<<" "<<s3<<std::endl;

	//partitions the range, returns an iterator to the partition point, maintains sorted order of elements
	std::stable_partition(s.begin(), s.end(), isdigit);
	std::cout<<s<<std::endl;
	
	//partitions the range, returns an iterator to the partition point, doesn't maintain order
	std::partition(s3.begin(), s3.end(), isdigit);
	std::cout<<s3<<std::endl;
	
	//returns the one past the first subrange iterator for a properly partitioned range
	auto it = std::partition_point(s.begin(), s.end(), isdigit);
	std::cout<<*it<<std::endl;

	return 0;
}
