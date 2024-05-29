#pragma once

#include<type_traits>

//int futurethreadproc(std::string s, std::promise<int> pr);
void caller(void);
struct compstr
{
	bool operator()(std::string a, std::string b) const
	{
		return( a < b ? 1 : 0);
	};
};

class SingletonTest
{
	static SingletonTest *mpInst_;
	SingletonTest();
public:
	

	static SingletonTest& getinst(void);
	static void close(void);
	~SingletonTest()
	{
		std::cout << "SingletonTest Destructor" << std::endl;
	};
	void print(void)
	{
		std::cout<<"SingletonTest print"<<std::endl;
	}
};
void SingletontestCaller(void);



int threadproc_01(int a1, int b1);
void call_threadproc_01(void);
void threadproc_02(void);

//std::vector<int>::iterator it;
template <class T>
 void func(T &v)
 {
	 const std::type_info &ty = typeid(v);
	 //now traverse the template
	 typename T::iterator it, it2;
	
	 it = v.begin();
	 it2 = v.end();
	// bool val = std::is_same<std::map<std::string, int>, decltype(v)>::value;
	 for(;it != it2; it++)
	 {

		//if(std::is_same<std::map<std::string, int>, decltype(v)>::value)
		//	std::cout<<"output from "<<ty.name()<<" "<<it->first<<" "<<it->second<<std::endl;
		//else 
		//	std::cout<<"output from "<<ty.name()<<" "<<*it<<std::endl;
	 }
	 

	 //it = v.begin();
	 //it2 = v.end();
	 //for(;it != it2;it++)
	 //{
		// std::cout<<"output from "<<ty.name()<<" "<<*it<<std::endl;
	 //}
 }
 /*
 template <template <typename...> class Container, class... T>
 void func(const Container<T...>& container) 
 {
	 if constexpr (std::is_same_v<Container<T...>, std::map<T...>>) {
		 ...
	 }
	 else if constexpr (std::is_same_v<Container<T...>, std::vector<T...>>) {
		 ...
	 }
	 else if constexpr (std::is_same_v<Container<T...>, std::list<T...>>) {
		 ...
	 }
	 else {
		 ...
	 }
 }
 */
 void somefunc(void);
 void somefunc2(void);
 void funcdigitcnt(void);
 bool findplendrom(std::string s);
 void signalhandler(int signal);

 