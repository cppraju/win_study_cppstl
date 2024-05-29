#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <memory>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <mutex>

//#include<time.h>

#include "logr.h"
#include "logger.h"


/*
#include <sys/time.h>

char fmt[64];
char buf[64];
struct timeval tv;
struct tm *tm;

gettimeofday (&tv, NULL);
tm = localtime (&tv.tv_sec);
strftime (fmt, sizeof (fmt), "%H:%M:%S:%%06u", tm);
snprintf (buf, sizeof (buf), fmt, tv.tv_usec);
printf ("%s\n", buf);

00:01:32:695240
--------------------------------------------------------------
 auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

	cout << ctime(&timenow) << endl;

*/
static std::chrono::high_resolution_clock::time_point _now;
static uint8_t gbuf[256];
static logger *gplogr = nullptr;
static std::mutex mu_log;
void  settimeprecision(TP v)
{
	if (gplogr != nullptr)
		gplogr->p = v;
}

void logger::getDateTime(std::string& strdt)
{
	struct tm _tm;
	errno_t et;
	char fmt[10], xxx[128];

	memset(fmt, 0, sizeof(fmt));
	memset(xxx, 0, sizeof(xxx));
	strcpy_s(fmt, "%F %T");
	std::chrono::high_resolution_clock::time_point hnow = std::chrono::high_resolution_clock::now();
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	
	if (p == TP::milli)
	{
		
		std::chrono::system_clock::time_point now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);				//time_point_cast
		std::chrono::system_clock::duration epoch = now_ms.time_since_epoch();														//duration
		std::chrono::duration<long long, std::milli> value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);			//duration_cast to milli
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
//#ifdef _DEBUG
//		std::cout <<"duration :" << epoch.count() << " duration_cast :" << value.count() << std::endl;
//#endif
		uint64_t msec = value.count() % 1000;
		et = localtime_s(&_tm, &now_c);
		std::strftime(xxx, sizeof(xxx) / sizeof(char), fmt, &_tm);
		sprintf_s(xxx, "%s.%03I64d", xxx, msec);
	}
	else if (p == TP::micro)
	{
		//std::chrono::high_resolution_clock::time_point now_us = std::chrono::time_point_cast<std::chrono::microseconds>(hnow);
		std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::microseconds> now_us = std::chrono::time_point_cast<std::chrono::microseconds>(hnow);				//time_point_cast
		std::chrono::duration<int64_t, std::micro> epoch = now_us.time_since_epoch();																								//duration
		std::chrono::duration<int64_t, std::micro> value = std::chrono::duration_cast<std::chrono::microseconds>(epoch);															//duration_cast to micro
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
//#ifdef _DEBUG
//		std::cout <<"duration :" << epoch.count() << " duration_cast :" << value.count() << std::endl;
//#endif
		uint64_t msec = (value.count() % 1000000) / 1000;
		uint64_t usec = (value.count() % 1000000) % 1000;
		et = localtime_s(&_tm, &now_c);
		std::strftime(xxx, sizeof(xxx) / sizeof(char), fmt, &_tm);
		sprintf_s(xxx, "%s.%03I64i:%03I64i", xxx, msec, usec);

	}

	//just checking
	
	strdt = xxx;
}
logger::~logger()
{
	if (fs.is_open())
		fs.close();
}

logger::logger(std::string filename) try : fs(filename, std::ios::app)
{
	std::string sintro = "________________<<<start logging>>>________________\n\n";
	fs.write(sintro.c_str(), strlen(sintro.c_str()));
}
catch (std::exception & e)
{
	std::cout << "Exception in constructor : Err code :"<<errno<<" Description :" << e.what() << std::endl;
}

bool initlogger(std::string filename)
{
	bool bRet = false;
	try
	{
		if (gplogr == nullptr)
		{
			gplogr = new(gbuf) logger(filename);
			bRet = true;
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Exception in initlogger : Error code :" << errno <<" Description :" << e.what() << std::endl;
		bRet = false;
	}
	return(bRet);
}

void logr(const std::string& str)
{
	std::string s;
	char buf[4096];
	std::ostringstream oss;
	std::lock_guard<std::mutex> lg(mu_log);
	gplogr->getDateTime(s);
	memset(buf, 0, sizeof(buf));
	oss<<std::this_thread::get_id();
	sprintf_s(buf, sizeof(buf), "%s [%s] %s Error Code :%d\n", s.c_str(), oss.str().c_str(), str.c_str(), errno);
	gplogr->fs.write(buf, strlen(buf));
}

void closelogger(void)
{
	if (gplogr != nullptr)
	{
//		std::string sintro = "________________<<<end logging>>>________________\n\n";
//		gplogr->fs.write(sintro.c_str(), strlen(sintro.c_str()));
		gplogr->~logger();
		gplogr = nullptr;
	}
}

void startTimer(void)
{
	_now = std::chrono::high_resolution_clock::now();
}
uint64_t getTimer(TP resolution)
{
	uint64_t msec = 0;
	switch (resolution)
	{
	case TP::milli:
		msec = (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - _now)).count() / 1000;
		break;
	case TP::micro:
		msec = (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - _now)).count();
		break;
	}
	return(msec);
}