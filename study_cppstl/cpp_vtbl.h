#pragma once

class base_
{
public:
	virtual void func1(void)
	{
		std::cout << "Hello from Base_" << std::endl;
	};

};

class derive_ :public base_
{
public:
	virtual void func2(void)
	{
		std::cout << "Hello from derive_" << std::endl;
	};
};

class someother_ /*:public virtual base_*/
{
public:
	virtual void somefunc(void)
	{
		std::cout << "Hello from someother_" << std::endl;
	};
};

class morederive_ :public derive_, public someother_
{
public:
	virtual void morederivefunc(void)
	{
		std::cout << "Hello from morederive_" << std::endl;
	};
};

