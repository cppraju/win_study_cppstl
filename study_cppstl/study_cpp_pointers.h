#pragma once


class BB
{
public:
	BB()	try : x(0)
	{
		std::cout << "B default constructor" << std::endl;
	}
	catch (std::exception * e)
	{
		std::cout << e->what() << std::endl;
	};
	int x;
	void f(int t)
	{
		x = t;
	};
};

void study_pointerstomembers(void);
void accessmultidimensionalarray(void);
void pass_array_in_func_01(int16_t (*pfn)[], int16_t row, int16_t col);
