class student
{
	char *name;
	int age;
public:
	student()
	{
		name = nullptr;
		age = 0;
	};
	student(char *pname, int ag)
	{
		name = new char[strlen(pname) + 1];
		memset(name, 0, strlen(pname) + 1);
		strcpy(name, pname);
		age = ag;
	};
	student(const student &othr)
	{
		name = new char[strlen(othr.name) + 1];
		memset(name, 0, strlen(othr.name) + 1);
		strcpy(name, othr.name);
		age = othr.age;
	};
	student & operator=(const student &other)
	{
		if(this != &other)
		{
			if( (name != nullptr)
				delete name;

			name = new char[strlen(othr.name) + 1];
			memset(name, 0, strlen(othr.name) + 1);
			strcpy(name, othr.name);
			age = othr.age;
		}
		return(*this);
	};
};

class school
{
	student *s;
public:
	school() : student(){};
	school(const student &othr) : student(othr)
	{
	};
	school(const school & sch) : student(sch.s)
	{
	};
	school & operator=(const school &othr)
	{
		if(this != &other)
		{
			s = othr.s;
		}
		return(*this);
	}


};

class testsingleton
{
public:
	static testsingleton *pInst_;
	testsingleton * getInst(int i)
	{
		if(pInst_[i] == nullptr)
			pInst_ = new testsingleton();
		return(pInst);
	};
};
void threadProc1(testsingleton *p)
{
	



}
void threadProc2(testsingleton *p)
{
	



}
void threadProc3(testsingleton *p)
{
	



}
void main(void)
{
	std::thread th[5];

	for()
	{
	future p = std::asyn(std::async,th[1], [](){
		return(testsingleton::getinst())})
			p.get();
	}
}

printcont(std::array<T> ma)
{


}

printcont(std::list<T> ma)
{


}


printcont(<typename T><int> ma)
{
	typeid
	std::<typename T><int>::iterator it;
	if(typeid != std::map)
	{
		for(it = ma.bigin(); it != ma.end(); it++)
		{
			std::cout<<*it

		}
	}
	else if(typeid != std::map)
	{
		for(it = ma.bigin(); it != ma.end(); it++)
		{
			std::pair<>
			std::cout<<it->

		}
}