#include <iostream>
#include <string.h>
using namespace std;
struct some
{
	int a, b, c;
	char ca, cb;
	some()
	{
		a = b = c = 0;
		ca = cb = 0;
	};
};
int ar[50];

int mainxx()
{
	unsigned char ss = 200;
	cout << "Hello World";
	struct some xx;
	memcpy_s(ar, 50, &xx, sizeof(xx));
	return 0;
}