int main()
{
	
	int i = 0, *const cp = &i;
	int *p1, *const p2 = &i;
	const int ic = 0, &r = ic;
	const int *const p3 = &i;
	const int *p = &i;	

	//all are illegal except i = ic, all others are attempting to assign to const variables
	i = ic;
	p1 = p3;
	p1 = &ic;
	p3 = &ic;
	p2 = p1;
	ic = *p3;

}
