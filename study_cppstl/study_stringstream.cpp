#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <assert.h>
#include <iterator>
#include <algorithm>

#include "logr.h"
#include "study_stringstream.h"


//std::istringstream& operator >>(std::istringstream& s, _personinfo& obj)
//{
//	char buf[4];
//	memset(buf, 0, sizeof(buf));
//	s >> obj._sname >> obj._age;
//	return(s);
//}
//std::ostringstream& operator <<(const _personinfo& obj, std::ostringstream& s)
//{
//	//char buf[4];
//	//std::ostringstream st(std::ios::ate);
//	//memset(buf, 0, sizeof(buf));
//	//_itoa_s(obj._age, buf, 10);
//	//s.str(obj._sname);
//	//s << obj._age;
//	//s = st;
//	//std::string st = obj._sname + " " + buf;
//	s << obj._sname << " " << obj._age;
//
//	return(s);
//}
std::istream& operator >>(std::istream& s, _personinfo& obj)
{
	s >> obj._sname >> obj._age;
	return(s);
}

std::ostream& operator<<(std::ostream& s, const _personinfo& obj)
{
	s << obj._sname << " " << obj._age;
	return(s);
}
void call_stringstream(void)
{
	_personinfo p;
	std::istringstream ss("raju 53");
	char sd[32];
	memset(sd, 0, sizeof(sd));
	std::stringstream s;
	ss >> p;
	int a = 10;
	double d = 234.098760001;
	s << "hello what is going on?";
	std::string st;
	s >> st;
	s << a;
	s << d;
	s.precision(10);
	s <<std::fixed<< d;
	s >> st;
	_gcvt_s(sd, sizeof(sd), d, 30);	//4double to string
	std::cout << std::endl;
}

void call_fstream(void)
{
	std::cout << "\n<-------------------call_fstream()------------------->\n";
	logr("\n<-------------------call_fstream()------------------->\n");
	std::fstream fs;
	std::string filename = "cpp11.h";
	uint8_t buf[256];
	std::streamoff  sf;
	int64_t fz;
	int8_t cnt = 0;
	

	try
	{
		fs.open(filename, std::ios::in);
		if (fs.is_open())
		{
			fs.seekg(0, std::ios_base::end);
			sf = fs.tellg();
			static_assert(sizeof(sf) <= sizeof(int64_t), "File size too large for int64!");
			fz = static_cast<int64_t>(sf);
			std::cout << "File size :" << fz << "\n";
			fs.seekg(0, std::ios_base::beg);
			while (!fs.eof())
			{
				memset(buf, 0, sizeof(buf));
				fs.getline((char*)buf, static_cast<std::streamsize>(sizeof(buf)), 0x0A);
				logr(reinterpret_cast<char*>(buf));
				std::cout << buf<<"\n";
			}
			fs.close();
		}
	}
	catch (std::exception & e)
	{
		std::cout << "call_fstream() Excepetion :" << e.what() << "\n";
	}

}

/*
 // read back from the file
	char a;
	std::cout << ((std::ifstream{file} >> a), a) << std::endl;
*/
void call_stringstream_morefeatures(void)
{
	std::istringstream iss("the quick brown fox jumps over lazy dogs");
	std::string is("the quick brown fox jumps over lazy dogs");

	std::istream_iterator<char> isit(iss);

	//with std::ostream_iterator
	std::ostream_iterator<char> osit(std::cout);
	std::copy_if(is.begin(), is.end(), osit, [](char a) {return(a != ' '); });
	std::cout << std::endl;

	//with std::ostreambuf_iterator
	std::ostreambuf_iterator<char> osbit(std::cout);
	std::copy_if(is.begin(), is.end(), osbit, [](char a) {return(a != ' '); });
	std::cout << std::endl;
}