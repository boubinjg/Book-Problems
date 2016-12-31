int main()
{
	//illegal not initialized
	//int i, *const cp;
	//illegal, not initialized
	//int *p1, *const p2;
	//illegal, ic must be initialized
	//const int ic, &r = ic;
	//illegal, not initialized
	//const int *const p3;
	//legal
	const int *p;
}
