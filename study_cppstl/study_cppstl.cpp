// study_cppstl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "cpp_vtbl.h"
#include "learn.h"
#include "producer_consumer.h"
#include "unordered_container.h"
#include "logr.h"

#include "learnAlgo.h"
#include "infinite.h"
#include "study_functional.h"
#include "study_cpp_pointers.h"
#include "study_stringstream.h"
#include "study_iterator.h"
#include "study_containerAdapters.h"
#include "observer_pattern.h"

int main()
{

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	initlogger();
	//somefunc();
	//somefunc2();
	//constexpr int x = 2;
	//addval<x>(10);


	int x = 10;
	float f = (float)1.2;
	/*----------------vtbl-----------------------------------
	base_ bobj;
	derive_ dobj;
	someother_ sobj;
	morederive_ mobj;

	x = sizeof(base_);
	x = sizeof(derive_);
	x = sizeof(someother_);
	x = sizeof(morederive_);

	base_ *pobj = nullptr;
	derive_* pdob = nullptr;
	someother_* psobj = nullptr;
	morederive_* pmobj = nullptr;

	pdob = new derive_();
	pmobj = new morederive_();

	delete pdob;
	delete pmobj;
	std::cout << "Hello Ending" << std::endl;
	----------------pointers-----------------------------------*/
	//study_pointerstomembers();
	accessmultidimensionalarray();

	//caller_unordered_cointainer();
	/*---------------------------------------------------*/
	/*std::map<std::string, int> m;
	bool val = std::is_same<std::map<std::string, int>, decltype(m)>::value;
	func(m)*/;
/*	------------------------------------------------------------*/

 	logr("this is some text");
	//closelogger();
	//SingletontestCaller();
	//findplendrom("abcdcba");
	//call_threadproc_01();
	/*---------------------stringstream----------------------------- - */
	//call_stringstream();
	call_stringstream_morefeatures();
	/*-------------------------------------------------- - */
		//algorithm;
	//try_for_each();
	//try_unique();
//	try_prioritylist();
	//run_producer_consumer();
	//call_fstream();
	/*----------------algorithm-----------------------------------*/
//	call_somefunc_infi();
//	try_algo_associativecontainer();
//	try_partition();
//	nth_element();
//	binarysearch();
//	reverse_rotate();
//	set_algo();
//	morealgo();
	/*--------------------functional-------------------------------*/
//	call_functional();
	/*--------------------iterators-------------------------------*/
//	call_streamiterators();
	/*------------------end---------------------------------*/
	/*------------------containerAdapters---------------------------------*/
//	callmemleak();
	/*-----------------------observer pattern--------------------------------*/
	callobserverpattern();

/*------------------end---------------------------------*/
	closelogger();
	return(0);

}