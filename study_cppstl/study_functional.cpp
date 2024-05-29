#include <iostream>
#include <deque>
#include <functional>
#include <algorithm>
#include <random>
#include <iterator>

#include "learnAlgo.h"
#include "study_functional.h"



void bind_func1(int16_t n, int32_t k, double_t &x, double_t &y, double_t &z)
{
	std::cout << "before modify :" << x << " " << y << " " << z << "\n";
	std::mt19937 var;
	x = x + (var() % 10) * .1;
	y = y + (var() % 10) * .1;
	z = z + (var() % 10) * .1;
	std::cout << "after modify :" << x << " " << y << " " << z << std::endl;
}

vertex& bind_func2(std::mt19937& var, double_t fv, vertex& v)
{
	v.x = v.x + (var() % 10) * fv;
	v.y = v.y + (var() % 10) * fv;
	v.z = v.z + (var() % 10) * fv;
	return(v);
}
void call_functional(void)
{
	std::deque<vertex> dqvert;
	//create an array of 100 vertex
	double_t x, y, z;
	std::mt19937 var;

	x = 2.0;
	y = 2.0;
	z = 2.0;
	for (uint8_t ui = 0; ui < 10; ++ui)
		dqvert.emplace_back(x, y, z);
	//using bind with transform
	std::transform(dqvert.begin(), dqvert.end(), dqvert.begin(), std::bind(bind_func2, var, .1, std::placeholders::_1));
	for (auto a : dqvert)
		std::cout << a.x << " " << a.y << " " << a.z << "\n";

	//now use bind with param in diff order of declaration
	auto fptr = std::bind(bind_func1, std::placeholders::_2, std::placeholders::_1, std::ref(y), std::ref(x), std::ref(z));
	fptr(4, 10, std::ref(x));
	
	//search_n
	std::deque<vertex>::iterator it = std::search_n(dqvert.begin(), dqvert.end(), 2, vertex(2, 2.6, 2.9));



	std::cout << std::endl;
}

void functional_misc(void)
{


}