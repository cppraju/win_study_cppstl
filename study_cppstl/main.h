
typedef struct ConsecutiveNumGroup
{
	int st;
	int end;
	int val;
	ConsecutiveNumGroup()
	{
		val = st = end = 0;
	};
}CNG, *LPCNG;

class tree
{
	int n;
	tree *lf;
	tree *rt;
public:
	tree();
	tree(int);
	friend void insert(tree *,int);
	//friend void show(tree *,int,int);
	int getvalue(void){return(this->n);};
	friend void inord(tree *);
	friend bool findnode(tree *pn, int val, tree **pret);
	//friend void preord(tree *);
	//friend void posord(tree *);
	//friend tree * del1(tree *,int);
	//friend tree * del2(tree *,int);
};
tree::tree()
{
	n=0;
	lf=NULL;
	rt=NULL;
}
tree::tree(int val)
{
	n=val;
	lf=NULL;
	rt=NULL;
}
struct change
{
    
    long c2;
    long b5;
    long b10;
    change()
    {
        c2 = b5 = b10 = 0;
    };
};

/*
	This will locate the biggest group of consecutive numbers from a group of numbers 
*/
CNG GetBiggestGrp(void);

/*
	Will Encrypt a given string in a series of 0
*/
void stringencryption(void);
/*
	compute minimum currency change
*/
void minchange(long s, change &c);

class single
{
	single()
		{
			std::cout<<"single::constructor called"<<std::endl;
		};
	~single()
	{
		std::cout<<"single::destructor called"<<std::endl;
	};
public:
	static single *sp;
	single *sp2;
	static single sp3;
	static single * getinst(void)
	{
		if(sp == NULL)
			sp = new single();
		return(sp);
	};
	single * getinst2(void)
	{
		if(sp2 == NULL)
			sp2 = new single();
		return(sp2);
	};
	static single getinst3(void)
	{
		return(sp3);
	};
	void show(void)
	{
		std::cout<<"single::show called"<<std::endl;
	};
	static void clearinst(void)
	{
		if(sp != NULL)
			delete(sp);
	};
};

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
		std::cout << "A :: Copy assignment operator called" << std::endl;
		if (this != &r)
		{
			delete[] p;
			a = r.a;
			p = new char[strlen(r.p) + 1];
			strcpy_s(p, strlen(r.p) + 1, r.p);
			printf("%s", r.p);
		}
		return(*this);
	};
	A& operator=(const A&& r)
	{
		std::cout << "A :: Move assignment operator called" << std::endl;
		if (this != &r)
		{
			delete[] p;
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
	friend std::ostream& operator<<(std::ostream &os, A &z);
	friend std::istream& operator>>(std::istream &is, A &z);
	~A()
	{
		delete [] p;
	}
};

std::ostream& operator<<(std::ostream &os, A &z)
{
	os<<z.a;
	return(os);
}
std::istream& operator>>(std::istream &is, A &z)
{
	is>>z.a;
	return(is);
}

class B : public A
{
public:
	B()	try : x(0), A()
	{
		std::cout<<"B default constructor"<<std::endl;
	}
	catch(std::exception *e)
	{
		std::cout<<e->what()<<std::endl;
	};
	int x;
	void f(int t)
	{
		x = t;
	};
};

