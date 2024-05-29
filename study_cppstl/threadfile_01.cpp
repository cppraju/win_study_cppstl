#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <typeinfo>
#include <map>
#include <future>
#include <chrono>

#include "learn.h"

static int a;
std::mutex m;


int threadproc_01(int a1, int b1)
{
	a = 20;
	std::cout<<"threadproc_01 calling "<<a<<std::endl;
	std::lock_guard<std::mutex> lg(m);
	int x = a1 + b1;
	std::cout<<"threadproc_01 calling "<<a<<std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	return(x);
}
void funcasyn(void)
{


}

void call_threadproc_01(void)
{
	std::future<int> fi;
	 
	fi = std::async(std::launch::async, threadproc_01, 2, 3);
	std::future<void> f = std::async(std::launch::async, funcasyn);
	std::cout << "future: " << fi.get() << std::endl;
	
}