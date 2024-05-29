#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include "study_iterator.h"

/*
	Iterator category:
	-Input iterator
	-Output Iterator
	-Foward Iterator
	-Bidirectional Iterator
	-RandomAccess Iterator
	-Contiguous Iterator

	Itrator Adapter - they are iterators with specific function on a specified container<type> like "back_inserter", "front_inserter"
	Stream iterators - they operate on streams, streambuf, stringstreams
	Iterator Operations - various operations supported on iterators like advance(), next()

*/
void call_streamiterators(void)
{
	//Stream Itrators
	std::string str;
	str = "somepeoplehavecurlybrownhair";

	std::istringstream iss(str);
	std::ostringstream oss;
	std::ostream os(std::cout.rdbuf());
	
	
	
	//using std::ostream_iterator with std::ostream
	std::ostream_iterator<char> osi(os, ", ");
	std::copy(str.begin(), str.end(), osi);
	std::cout << std::endl;

	//using std::ostreambuf_iterator with std::ostream
	std::ostreambuf_iterator<char> osbi(std::cout);
	std::copy(str.begin(), str.end(), osbi);
	std::cout << std::endl;

	//using std::ostream_iterator with std::ostringstream
	std::ostream_iterator<char> osi2(oss, ", ");
	std::copy(str.begin(), str.end(), osi2);
	std::cout << oss.str();
	std::cout << std::endl;

	//using std::ostreambuf_iterator with std::ostringstream
	oss.seekp(0, std::ios_base::beg);
	std::ostreambuf_iterator<char> osbi2(oss);
	std::copy(str.begin(), str.end(), osbi2);
	std::cout << oss.str();
	std::cout << std::endl;
	//read a file and 
	try
	{

	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
}