#include<string>
#include"14.2.h"
#ifndef TOKEN
#define TOKEN
using std::string;
class Token {
public:
	Token() : tok(INT), ival(0) {}
	Token(const Token &t) : tok(t.tok) {copyUnion(t);}
	Token &operator=(const Token&);
	~Token() {if(tok == STR) sval.~string(); if(tok == SD) sd.~Sales_data(); }
	
	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
private:
	enum {INT, CHAR, DBL, STR, SD} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sd;
	};
	void copyUnion(const Token&);
};

#endif
