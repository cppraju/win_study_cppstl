#include <iostream>
#include <sstream>
#include <signal.h>


#include "study_cpp_pointers.h"

//pointers to members
void study_pointerstomembers(void)
{
	int BB::* pm = &BB::x;
	void (BB:: * pfn)(int) = &BB::f;
	BB* pobj;
	BB tem;
	pobj = &tem;
	//accessing pointer to members using object
	tem.*pm = 20;
	(tem.*pfn)(40);
	//accessing pointer to members using pointers
	(pobj->*pfn)(30);
	pobj->*pm = 30;
}

/*
const uint8_t* in = &inputBuf[2*channels*i];
			buf[i] = in[0] | (in[1] << 8);
*/

void accessmultidimensionalarray(void)
{
	//both ways are basically the same
	int16_t ar[3][4] = { 1,2,3,4,
					   5,6,7,8,
					   9,10,11,12};
	int16_t ar2[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	{
		//declare an array of pointers and use that to create and access the 2d array
		int16_t* par[3] = { nullptr, nullptr, nullptr };
		std::ostringstream oss;
		for (int16_t i = 0; i < 3; ++i)
			*(par + i) = new int16_t[4];
		for (int16_t a = 0; a < 3; ++a)
			for (int16_t j = 0; j < 4; ++j)
			{
				*(*(par + a) + j) = ar[a][j];
				oss << *(*(par + a) + j) << " ";
			}
		std::cout << oss.str();
		//cleanup
		for (int16_t x = 0; x < 3; ++x)
			delete[]*(par + x);
		std::cout << std::endl;
	}
	{
		//declare an 2d array using pointer to pointer
		int16_t** ppar = nullptr;
		std::ostringstream oss;
		ppar = new int16_t *[3];
		for (int16_t i = 0; i < 3; ++i)
			*(ppar + i) = new int16_t[4];
		for (int16_t a = 0; a < 3; ++a)
			for (int16_t j = 0; j < 4; ++j)
			{
				*(*(ppar + a) + j) = ar[a][j];
				oss << *(*(ppar + a) + j) << " ";
			}
		std::cout << oss.str();
		//cleanup
		for (int16_t x = 0; x < 3; ++x)
			delete[] * (ppar + x);
		delete[]ppar;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
//pass array to a func
void pass_array_in_func_01(int16_t (*pfn)[], int16_t row, int16_t col)
{

}