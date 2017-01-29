#include"12.33.h"
class Query_base{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:	
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string ret() const = 0;
};
