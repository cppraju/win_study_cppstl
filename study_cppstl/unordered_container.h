#pragma once

enum dimension
{
	_2D,
	_3D
};

typedef struct point
{
	dimension d;
	double x_;
	double y_;
	double z_;
	point(double x = 1.0, double y = 1.0, double z = 1.0, dimension dm = _3D) : x_(x), y_(y), z_(z), d(dm)
	{}
	/*
	bool operator==(const point& othr) const
	{
		std::cout << "From struct point" << std::endl;
		return((x_ == othr.x_) && (y_ == othr.y_) && (z_ == othr.z_) && (d == othr.d));
	}*/
}POINT, *LPPOINT;

struct cpt
{
	bool operator ()(const POINT& a, const POINT& b) const
	{
		return(a.x_ < b.x_);
	}
};
class pointhash
{
public:
	size_t operator()(const point& pt) const
	{
		return((size_t)(pt.x_ + pt.y_ + pt.z_));
	}
};

struct cmppt
{
	bool operator()(const point& a, const point& b) const
	{
		return((a.x_ == b.x_) && (b.y_ == a.y_) && (a.z_ == b.z_) && (a.d == b.d));
	};
};


bool fcmppt(const point& a, const point& b);

typedef bool(*CMPPT_FPTR)(const point& a, const point& b);

void caller_unordered_cointainer(void);