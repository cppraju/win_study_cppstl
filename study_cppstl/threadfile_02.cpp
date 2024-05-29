#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <typeinfo>
#include <map>

#include "learn.h"

static int a;
extern std::mutex m;




void threadproc_02(void)
{
	a = 10;
	std::cout<<"threadproc_02 calling "<<a<<std::endl;
//	std::lock_guard<std::mutex> lg(m);
	SingletonTest::getinst().print();
//	SingletonTest::close();
	std::cout<<"threadproc_02 calling "<<a<<std::endl;
}