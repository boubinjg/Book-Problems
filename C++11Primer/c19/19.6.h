#include"12.33.h"
class QueryBase {
public:
	QueryBase(){}
	virtual ~QueryBase() {}
};
class BinaryQuery : public QueryBase {
public:
	BinaryQuery() : QueryBase() {}
	virtual ~BinaryQuery() {}
};
class AndQuery : public BinaryQuery {
public: 
	AndQuery() : BinaryQuery() {}
	virtual ~AndQuery() {}
};

