#pragma once



/*
	demonstarting a memory leak without calling new
*/
struct V :std::vector<V>
{

};

void callmemleak(void);