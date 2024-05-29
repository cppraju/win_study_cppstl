#include <iostream>
#include <future>

#include "observer_pattern.h"

void Obsrvr::obsrv_callback(void *pd)
{
		//do somthing as per requirement 
		//this may or may not be a blocking call
	std::cout << "notify calling CALLBACK\n";
}
void Obsrvr::callbyasync(void)
{
	std::cout << "\ncall by async\n";
}

void callobserverpattern(void)
{
	Obsrvr obsObj = Obsrvr();
	Obsrvr o = obsObj;
	SubjectToObserv so;
	so.attach(Obsrvr::obsrv_callback);
	
	std::future<void> f = std::async(std::launch::async, &Obsrvr::callbyasync, & obsObj);
	//in some other code when SubjectToObserv will notify
	f.get();
	
	someObrsvfunc(o);
	someObrsvfunc(std::move(Obsrvr()));
	someObrsvfunc2(Obsrvr());
	so.notify();
}
	
void someObrsvfunc(Obsrvr v)
{


}

void someObrsvfunc2(Obsrvr&& v)
{

}
