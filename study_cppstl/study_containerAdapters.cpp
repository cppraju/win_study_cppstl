#include <iostream>
#include <vector>

#include "study_containerAdapters.h"


void callmemleak(void)
{
	V v;
	v.emplace_back();
	v.swap(v.front());

}