#include <iostream>
#include <set>
#include <unordered_set>
#include <signal.h>

#include "unordered_container.h"

/*
	signal handler to handle access violation
*/
void signalhandler(int signal)
{
	throw(std::overflow_error("\n...............Access Violation...............\n"));
}

typedef void (*FPTR_sighdl)(int);

/*
Notes:-
supply the equal to == operator either as member of the userdefined structure [best]  
as a functor with operator()(const typename obj1, const typename obj2) doing the == compare
declare a compare function 
*/
bool fcmppt(const point& a, const point& b)
{
	std::cout << "From cmppt" << std::endl;
	return((a.x_ == b.x_) && (b.y_ == a.y_) && (a.z_ == b.z_) && (a.d == b.d));
};

void caller_unordered_cointainer(void)
{
	CMPPT_FPTR cpf = fcmppt;
	FPTR_sighdl fn_prev = nullptr;

	fn_prev = signal(SIGSEGV, signalhandler);	//trying to catch "access violation

	{
		std::unordered_set<POINT, pointhash, cmppt> ptset;
		//	std::unordered_set<POINT, pointhash, decltype(cpf)> ptset;		//will not work
		//	std::unordered_set<POINT, pointhash, CMPPT_FPTR> ptset(cpf);	//will not work
		std::set<POINT, cpt> spt;
		ptset.insert(POINT(1.2, 2.3));
		ptset.insert(POINT(1.2, 2.3, 4.5));
		ptset.insert(POINT(1.2, 2.3));
		ptset.emplace(1.2, 2.5);
		std::unordered_set<POINT, pointhash, cmppt>::iterator mit = ptset.begin();
		mit = mit++;
		ptset.emplace_hint(mit, 9.8, 5.6);
		std::cout << "unordered_set bucket count :" << ptset.bucket_count() << "\n";
		mit = ptset.find(POINT(1.2, 2.3));
		if (mit != ptset.end())
			std::cout << "node found node :" << mit->x_ << " " << mit->y_ << " " << mit->z_ << "\n";
		else
			std::cout << "Node not found." << std::endl;
	}


	std::cout << "\n\nWorking with unordered_multiset--------------------------\n\n";
	{
		std::unordered_multiset<POINT, pointhash, cmppt> ums;
		ums.insert(POINT(1.2, 2.3));
		ums.insert(POINT(1.2, 2.3));
		ums.emplace(1.2, 2.3);
		std::unordered_multiset<POINT, pointhash, cmppt>::iterator it = ums.find(POINT(1.2, 2.3));
		ums.emplace_hint(it, POINT(1.2, 2.3, 9));
		ums.emplace(3, 5, 6);
		ums.emplace(3, 5, 6);
		ums.emplace(5, 5, 5);
		for (it = ums.begin(); it != ums.end(); it++)
			std::cout << "x :" << it->x_ << " y :" << it->y_ << " z :" << it->z_ << "\n";
		try
		{
			std::cout << "Doing the extraction.............\n";
			std::_Node_handle n = ums.extract(POINT(1.2, 2.3));
			ums.insert(std::move(n));
			for (it = ums.begin(); it != ums.end(); it++)
				std::cout << "x :" << it->x_ << " y :" << it->y_ << " z :" << it->z_ << "\n";
			std::cout << "\nAftermoving the extracted node back trying to print the same..\n";
			//this will throw an "access violation error. How to catch that?
			std::cout << n.value().x_ << std::endl;
		}
		catch (std::exception &o)
		{
			std::cout << "exception on extract :" << o.what() << std::endl;
		}
		
	}
	std::cout << std::endl;
}
