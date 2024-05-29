#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <vector>
#include <queue>

//global variables
uint32_t icnt = 1;
const unsigned __int8 buff_size = 1;
std::queue<int32_t> qbuf;
std::condition_variable cv_full, cv_empty;
std::mutex mul;

uint32_t producer_proc(uint32_t indx)
{

	std::unique_lock<std::mutex> ul(mul, std::defer_lock);
	__int16 irun = 8;
	do
	{
		ul.lock();
		cv_full.wait(ul, [&](void) {return(icnt <= buff_size); });
		qbuf.push(std::rand());
		std::cout <<irun<<" Producer Thread :" << indx << " Value :" << qbuf.back() << " Count :" << icnt << std::endl;
		icnt = icnt + 1;
		cv_full.notify_all();
		ul.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		irun = irun - 1;
	} while (irun > 0);
	return(0);
}
uint32_t consumer_proc(uint32_t indx)
{
	std::unique_lock<std::mutex> ul(mul, std::defer_lock);
	__int16 irun = 8;

	do
	{
		ul.lock();
		cv_full.wait(ul, [&](void) {return(icnt > 1); });
		std::this_thread::sleep_for(std::chrono::milliseconds(900));
		int32_t val = qbuf.front();
		qbuf.pop();
		icnt = icnt - 1;
		std::cout <<irun<<" Consumer Thread :" << indx << " Value :" << val << " Count :" << icnt << std::endl;
		cv_full.notify_all();
		ul.unlock();
		irun = irun - 1;
	} while (irun > 0);
	return(0);
}

void run_producer_consumer(void)
{
	std::vector<std::thread> pth, cth;

	for (int i = 0; i < 2; i = i + 1)
		pth.emplace_back(std::thread(producer_proc, i + 1));
	for (int i = 0; i < 2; i = i + 1)
		cth.emplace_back(std::thread(consumer_proc, i + 1));
	/////join//////////////////
	for (int i = 0; i < 2; i++)
		pth[i].join();
	for (int i = 0; i < 2; i++)
		cth[i].join();
}