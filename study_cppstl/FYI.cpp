#include <iostream>
/*
[3:28 PM] Pathak, Amaresh

class A

{

public:



	virtual void func1()

	{

		cout << "in func1";

	}



	void func2()

	{

		cout << "in func 2";

	}



	virtual void func3()

	{

		cout << "in func3";

	}



};

class B : public A

{

public:

	void func1()

	{

		cout << "in Derived func1";

	}

	virtual void func2()

	{

		cout << "in derived func 2";

	}

	void func4()

	{

		cout << "in derived func4"

	}

};

int main()

{

	A* b = new B();

	b->fun1(); // "in Derived func1";

	b->fun2(); //"in derived func 2"

	b->fun3(); //in func3"

	b->fun4(); //

	return 0;

}
class abc
{
public:
	char* ptr;
	int a;
	static int b;
	abc(const abc& oth)
	{
		ptr = new char[strlen(oth.ptr) + 1];
		memset(ptr, 0, sizeof(char) * (strlen(oth.ptr) + 1));
		strcpy_s(ptr, othr.ptr);
		a = othr.a;
	}
	abc& operator =(const abc& othr)
	{
		if (this != &othr)
		{
			if (ptr != nullptr)
				delete[] ptr;

			ptr = new char[strlen(oth.ptr) + 1];
			memset(ptr, 0, sizeof(char) * (strlen(oth.ptr) + 1));
			strcpy_s(ptr, othr.ptr);
			a = othr.a;
		}
		return(*this);
	}
};

int abc::b = 0;

p[0]
p[1]

int** po;

int** p;
for (int i = 0; i < 4; i++)
{
	p[i] = new int

}
(p + 0)->
(p + 1)->
po = p;
*/