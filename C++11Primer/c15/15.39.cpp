#include"15.35.h"
#include<set>
#include<algorithm>

QueryResult OrQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}
QueryResult AndQuery::eval(const TextQuery& text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
		std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
QueryResult NotQuery::eval(const TextQuery& text) const
{
	auto results = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = results.begin(), end = results.end();
	auto sz = results.get_file()->size();
	for(size_t n = 0; n != sz; ++n) {
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, results.get_file());
a}
int main()
{
	return 0;
}
