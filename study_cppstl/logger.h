#pragma once

class logger
{
	logger(std::string filename);
	std::fstream fs;
	bool m_bloginit = false;
	TP p = TP::micro;
public:
	logger() = delete;
	logger(const logger &othr) = delete;
	logger& operator=(const logger &othr) = delete;
	~logger();

	void getDateTime(std::string& strdt);
	friend void  settimeprecision(TP v);
	friend bool initlogger(std::string filename);
	friend void logr(const std::string &str);
	friend void closelogger(void);
};


