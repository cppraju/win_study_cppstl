#include <iostream>

int f1(void)
{
	int t;
	t = 10;
	return(t);
}

void tmain(void)
{
	printf("%d", f1());
}

int f1(int &t)
{
	t = 10;
	return(0);
}

void wtmain(void)
{
	int t;
	f1(t);
	printf("%d", t);
}