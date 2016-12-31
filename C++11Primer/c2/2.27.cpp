int main()
{
	int i = 0,  i2 = 0;
	//illegal, r cant reference literal
	//int i = -1, &r = 0;
	//legal
	int *const p2 = &i2;
	//legal
	const int i3 = -1, &r2 = 0;
	//legal
	const int *const p3 = &i2;
	//legal
	const int *p1 = &i2;
	//illegal
	//const int &const r2;
	//legal
	const int i4 = i, &r3 = i;
}
