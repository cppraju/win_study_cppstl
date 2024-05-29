class A
{	
	int a;
	char *p;
public:

	A()
	{
		std::cout<<"A :: Default constructor called"<<std::endl;
		a = 0;
		p = new char[10];
		memset(p, 0, 10);
		strcpy_s(p, 10, "Hello");
	};
	A(int z)
	{
		std::cout<<"A :: One arg constructor called"<<std::endl;
		a = z;
		p = new char[10];
		memset(p, 0, 10);
		strcpy_s(p, 10, "Hello");
	}
	A(const A& r)
	{
		std::cout<<"A :: Copy constructor called"<<std::endl;
		a = r.a;
		p = new char[strlen(r.p)+1];
		strcpy_s(p, strlen(r.p)+1, r.p);
	};
	A(A&& r)
	{
		std::cout<<"A :: Move constructor called"<<std::endl;
		a = r.a;
		p = r.p;
		r.p = nullptr;
	};
	A& operator=(const A& r)
	{
		std::cout<<"A :: Copy assignment operator called"<<std::endl;
		if(this != &r)
		{
			delete [] p;
			a = r.a;
			p = new char[strlen(r.p)+1];
			strcpy_s(p, strlen(r.p)+1, r.p);
			printf("%s", r.p);
		}
		return(*this);
	};
	A& operator=(const A&& r)
	{
		std::cout<<"A :: Move assignment operator called"<<std::endl;
		if(this != &r)
		{
			delete [] p;
			a = r.a;
			p = r.p
			r.a = 0;
			r.p = nullptr;
		}
		return(*this);
	};	
	operator int(void)
	{
		return(a);
	};
	~A()
	{
		delete [] p;
	}
};
