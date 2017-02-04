#include<iostream>
#include<sstream>
#include<string>
#include<memory>

template<typename T> std::string debug_rep(const T&);
template<typename T> std::string debug_rep(T*);
std::string debug_rep(const std::string &s);
std::string debug_rep(char*);
std::string debug_rep(const char*);

template <typename T, typename ... Args>
std::ostream& print(std::ostream&, const Args& ...);
template <typename T> std::ostream& print(std::ostream& os, T& t);
template <typename ... Args>
std::ostream& errorMessage(std::ostream& os, const Args ... rest);


template <typename T> std::string debug_rep(const T &t)
{
        std::ostringstream ret;
        ret << t;
        return ret.str();
}
template <typename T> std::string debug_rep(T *p)
{
        std::ostringstream ret;
        ret << "pointer : " << p;
        if(p)
                ret <<" "<<debug_rep(*p);
        else
                ret << "null ptr";
        return ret.str();
}
std::string debug_rep(const std::string &s)
{
        return '"' + s + '"';

}
std::string debug_rep(char* p)
{
        return debug_rep(std::string(p));
}
std::string debug_rep(const char *p)
{
        return debug_rep(std::string(p));
}

template <typename T>
std::ostream& print(std::ostream& os, const T& t)
{
        return os<<t;
}
template <typename T, typename ... Args>
std::ostream& print(std::ostream& os, const T &t, const Args& ... rest)
{
        std::cout<<t<<" ";
        return print(os, rest...);
}

template <typename ... Args>
std::ostream& errorMessage(std::ostream& os, const Args ... rest)
{
	return print(os, debug_rep(rest)...);
}
int main()
{
	std::string s = "asdf";
	errorMessage(std::cout, "asdf","asdf","asdf",5,6,7);
	std::cout<<std::endl;
	return 0;	
}
