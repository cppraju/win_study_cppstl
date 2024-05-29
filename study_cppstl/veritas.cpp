#include <iostream>
#include <string>
#include <vector>


#include "learn.h"
/*
	Problem:
	take some integers as input if the count of digits in an integer is <= 5 then print 
	sum of the digits else print the product of the digits
*/

void funcdigitcnt(void)
{
	std::string s;
	std::vector<int> v;
	char buf[1024];
	char* pToken, * pContext = nullptr;
	long l;
	memset(buf, 0, sizeof(buf));
	std::cout << "input integers :";
	std::getline(std::cin, s);
	strcpy_s(buf, s.c_str());
	std::cout << std::endl;
	pToken = strtok_s(buf, " ", &pContext);
	while (pToken != NULL)
	{
		l = strtol(pToken, NULL, 10);
		//we will now count the digits
		int t = l;
		int val = 0;
		while (t != 0)
		{
			v.push_back(t % 10);
			t = t / 10;
		}
		//digits are now in vector
		if (v.size() <= 5)
		{
			val = 0;
			for (auto a : v)
			{
				val = val + a;
			}
		}
		else
		{
			val = 1; //initializing with 1 because we will *
			for (auto a : v)
			{
				val = val * a;
			}
		}
		std::cout << val << " ";
		v.clear();
		pToken = strtok_s(NULL, " ", &pContext);
	}
}