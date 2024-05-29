#pragma once
#include <random>


void call_functional(void);
void bind_func1(int16_t n, int32_t k, double_t& x, double_t& y, double_t& z);
vertex& bind_func2(std::mt19937& var, double_t fv, vertex& v);
void functional_misc(void);