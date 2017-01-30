#include"12.33.h"
class Query_base{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:	
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class Query{
friend Query operator~(const Query &);
friend Query operator|(const Query&, const Query&);
friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string&);
	QueryResult eval(const TextQuery &t) const
		{return q->eval(t);}
	std::string rep() const { return q->rep();}
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {} 
	std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) {std::cout<<"WordQuery Constructor"<<std::endl;}
	QueryResult eval(const TextQuery &t) const {return t.query(query_word); }
	std::string rep() const {std::cout<<"WordQuery Rep"<<std::endl; return query_word;}
	std::string query_word;
};

class NotQuery : public Query_base{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {std::cout<<"NotQuery Constructor"<<std::endl;}
	std::string rep() const {std::cout<<"NotQuery Rep"<<std::endl; return "~("+query.rep() + ")";}
	QueryResult eval(const TextQuery&) const;
	Query query;
};

class BinaryQuery : public Query_base{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s) {std::cout<<"BinQuery Constructor"<<std::endl;}
	std::string rep() const {std::cout<<"BinQuery Rep"<<std::endl;
			         return "("+rhs.rep()+" "+opSym+" "+lhs.rep()+")";}
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {std::cout<<"AndQuery Constructor"<<std::endl;}
	QueryResult eval(const TextQuery&) const;
};

class OrQuery : public BinaryQuery{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {std::cout<<"OrQuery Constructor"<<std::endl;}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator~(const Query &op)
{
	return std::shared_ptr<Query_base>(new NotQuery(op));
}

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {std::cout<<"Query Constructor"<<std::endl;}

std::ostream & operator<<(std::ostream &os, const Query &query)
{
	return os<<query.rep();
}
