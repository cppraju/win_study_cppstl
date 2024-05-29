#pragma once

class _base
{
public:
	_base() {};
	virtual void show(void) = 0;
};

class _derv1 : public _base
{
public:
	_derv1() : _base()
	{

	};
	virtual void show(void)
	{
		std::cout << "From _derv1" << std::endl;
	};
};

class _derv2 : public _base
{
public:
	_derv2() : _base()
	{

	};
	virtual void show(void)
	{
		std::cout << "From _derv2" << std::endl;
	};
};

void call_somefunc_infi(void);
void somefunc_infi(_base* pb);

class _node
{
public:
	int n;
	_node* pnext = nullptr;
};

_node* mergelist(_node* h1, _node* h2);
