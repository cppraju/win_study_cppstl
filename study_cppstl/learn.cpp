#include <iostream>
#include <vector>
#include <future>
#include <string>
#include <list>
#include <numeric>
#include <functional>
#include <thread>
#include <typeinfo>
#include <map>


#include "learn.h"
//
//int futurethreadproc(std::string s, std::promise<int> pr)
//{
//	int iRet = 100;
//	int a[6] = {2, 3, 5, 6, 7, 9};
//	std::vector<int> v;
//
//	for(int x : a)
//		v.push_back(x);
//	int sum = std::accumulate(v.begin(), v.end(), 10);
//	pr.set_value(sum);
//	return(iRet);
//}
//
//
//void caller(void)
//{
//	std::promise<int> pr;
//	std::future<int> fu = pr.get_future();
//	std::string s = "hello world";
//	std::thread thr(futurethreadproc, s, std::move(pr));
//
//	std::cout<<"future value :"<<fu.get();
//	thr.join();
//
//
//	
//
//}
//trailing return type
auto somefun(int  a) -> decltype (a)
{
	auto b = a + 'H';
	return(b);
};
void amain()
{
	auto a = somefun('B');
}

SingletonTest * SingletonTest::mpInst_ = nullptr;
SingletonTest&  SingletonTest::getinst(void)
{
	if(mpInst_ == nullptr)
	{
		mpInst_ = new SingletonTest();
		std::cout<<"Allocating Singleton"<<std::endl;
	}
	return(*mpInst_);
}
void SingletonTest::close(void)
{
	if (mpInst_ != nullptr)
		delete mpInst_;
	std::cout<<"Deallocating Singleton"<<std::endl;
}
SingletonTest::SingletonTest()
{

}
void SingletontestCaller(void)
{
	SingletonTest::getinst().print();
	SingletonTest obj = SingletonTest::getinst();
	obj.print();
	wchar_t buf[128];
	memset(buf, 0, sizeof(buf));
	SingletonTest* p = &SingletonTest::getinst();

	swprintf_s(buf, sizeof(buf) / sizeof(wchar_t), L"Address of stat :%p Addr of othr :%p", p, &obj);
	std::cout <<buf<< std::endl;
	
	SingletonTest obj2 = obj;

	SingletonTest::close();
}

void caller(void)
{

	std::thread t1(threadproc_01, 10, 20);
	std::thread t2(threadproc_02);

	t1.join();
	t2.join();
}

void somefunc(void)
{
	std::list<int> l;
	l.push_back(9);
	func(l);

}

void somefunc2(void)
{
	/*	 std::vector<int> v;
		 std::map<std::string, int, compstr> m;
		 char buf[32];
		 for(int i=0; i<10; i = i +1)
		 {
			 memset(buf, 0, sizeof(buf));
			 sprintf_s(buf, "somestr_%0d", i);
			 v.push_back(i+10);
			 m.insert(std::make_pair(buf, i+10));
		 }
		 func(v);
		 func(m);
	*/
}