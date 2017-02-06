#include<iostream>
#include<fstream>
#include<string>
int main()
{
	std::fstream inOut("17.39.txt", 
		       std::fstream::ate | std::fstream::in | std::fstream::out);
	if(!inOut) {
		std::cerr << "cant open file"<<std::endl;
		return EXIT_FAILURE;
	}
	
	auto end_mark = inOut.tellg();
	inOut.seekg(0, std::fstream::beg);
	size_t cnt = 0;
	std::string line;
	while(inOut && inOut.tellg() != end_mark && std::getline(inOut, line)) {
		cnt += line.size() + 1;
		auto mark = inOut.tellg();
		inOut.seekp(0, std::fstream::end);
		inOut << cnt;
		if(mark != end_mark) inOut << " ";
		inOut.seekg(mark);
	}
	inOut.seekp(0, std::fstream::end);
	inOut << "\n";
	return 0;
}
