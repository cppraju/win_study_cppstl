#pragma once
#include <deque>

void try_for_each(void);
void try_unique(void);
void try_prioritylist(void);
void try_algo_associativecontainer(void);

struct vertex
{
	double_t x;
	double_t y;
	double_t z;
	vertex() :x(0), y(0), z(0){};
	vertex(double_t x_, double_t y_, double_t z_) :x(x_), y(y_), z(z_) {};
	vertex(const vertex& othr)
	{
		x = othr.x;
		y = othr.y;
		z = othr.z;
	};
	vertex& operator=(const vertex& othr)
	{
		if (this != &othr)
		{
			x = othr.x;
			y = othr.y;
			z = othr.z;
		}
		return(*this);
	};
	vertex(vertex&& othr)
	{
		x = othr.x;
		y = othr.y;
		z = othr.z;
	};
	vertex& operator=(const vertex&& othr)
	{
		if (this != &othr)
		{
			x = othr.x;
			y = othr.y;
			z = othr.z;
		}
		return(*this);
	};
	bool operator==(const vertex& obj)
	{
		return((x == obj.x) && (y == obj.y) && (z == obj.z));
	}
};
struct vertexhash
{
	size_t operator()(vertex a) const
	{
		return((size_t)(a.x + a.y + a.z) / 10);
	};
};

struct edge
{
	std::pair<vertex, vertex> edg;
	edge() :edg(std::make_pair(vertex(), vertex()))
	{};
};

struct edgehash
{
	size_t operator()(edge e) const
	{
		return(vertexhash()(e.edg.first) + vertexhash()(e.edg.second));
	};
};

struct shape
{
	std::deque<vertex> vque;
	shape() :vque(5) {};
};
struct hashint32
{
	size_t operator()(int32_t v) const
	{
		return(v + 2);
	};
};
struct cmpint32
{
	bool operator()(int32_t a, int32_t b) const
	{
		return(a == b);
	}
};
void try_partition(void);
void nth_element(void);
void binarysearch(void);
void reverse_rotate(void);
void set_algo(void);
void morealgo(void);

bool predfind_if(vertex a, double b);
bool predfind_if2(double b, vertex a);
struct cmpfindif
{
	bool operator()(vertex a, double b) const
	{
		return(a.x == b);
	}
};