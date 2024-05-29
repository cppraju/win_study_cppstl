#pragma once

typedef enum class _timeprecision_
{
	nano,
	micro,
	milli
}TP;

void  settimeprecision(TP v);
bool initlogger(std::string filename = "issue.log");
void logr(const std::string& str);
void closelogger(void);
//start the timer
void startTimer(void);
//get the time spent in milli/micro sec
uint64_t getTimer(TP resolution = TP::milli);