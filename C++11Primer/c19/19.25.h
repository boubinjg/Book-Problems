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
	
	Token &operator=(const string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
	Token &operator=(const Sales_data&);
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
void Token::copyUnion(const Token &t)
{
	switch (t.tok) {
		case Token::INT: ival = t.ival; break;
		case Token::DBL: dval = t.dval; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::STR: new(&sval) string(t.sval); break; 
		case Token::SD: new(&sd) Sales_data(t.sd); break;
	}
}
Token &Token::operator=(int i)
{
	if(tok == STR) sval.~string();
	if(tok == SD) sd.~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}
Token &Token::operator=(char c)
{
	if(tok == STR) sval.~string();
	if(tok == SD) sd.~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}
Token &Token::operator=(double d)
{
	if(tok == STR) sval.~string();
	if(tok == SD) sd.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}
Token &Token::operator=(const string& s)
{
	if(tok == STR) 
		sval = s;
	else
		new(&sval) string(s);
	if(tok == SD) sd.~Sales_data();
	tok = STR;
	return *this;
}
Token &Token::operator=(const Sales_data& s)
{
	if(tok == SD) 
		sd = s;
	else
		new(&sd) Sales_data(s);
	if(tok == STR) sval.~string();
	tok = SD;
	return *this;
}
#endif
