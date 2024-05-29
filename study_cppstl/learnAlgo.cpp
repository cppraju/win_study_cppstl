#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <execution>
#include <functional>
#include <queue>
#include <unordered_set>
#include <set>
#include <iterator>
#include <forward_list>
#include <array>

#include "logr.h"
#include "learn.h"
#include "learnAlgo.h"


void try_for_each(void)
{
	std::vector<int> vec(10000);
	std::srand(99);
	int x = 0;
	for (int i = 0; i < 10000; i = i + 1)
		vec[i] = (rand() % 10000);

	std::chrono::high_resolution_clock::time_point now_01 = std::chrono::high_resolution_clock::now();
	std::for_each(vec.begin(), vec.end(), [&](int v) 
		{
			vec[x] = vec[x] + v % 10;
			x = x + 1;
		});
	std::chrono::duration dms = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - now_01);
	std::cout << "Time taken for 1st for_each:" << dms.count() << std::endl;

	x = 0;
	std::chrono::high_resolution_clock::time_point now_02 = std::chrono::high_resolution_clock::now();
	std::for_each(std::execution::par, vec.begin(), vec.end(), [&](int v)
		{
			vec[x] = vec[x] + v % 10;
			x = x + 1;
		});
	std::chrono::duration  t2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - now_02);
	std::cout << "Time taken for 2nd for_each:" << t2.count() << std::endl;
}

void try_unique(void)
{
	std::vector<int> v = { 1, 2, 56, 1, 1, 5, 5, 9, 45, 9, 10, 45, 6, 90, 8, 56, 4, 4, 2, 10 };
	std::sort(v.begin(), v.end(), std::greater<int>());
	std::vector<int>::iterator it = std::unique(v.begin(), v.end());
	v.erase(it, v.end());
	for (auto a : v)
		std::cout << a << " ";
	std::cout << std::endl;
}
void try_prioritylist(void)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	std::vector<int> v =  { 1, 2, 56, 1, 1, 5, 5, 9, 45, 9, 10, 45, 6, 90, 8, 56, 4, 4, 2, 10 };	//{ 23, 45, 2, 5, 78, 33, 11, 12, 7, 45, 76, 91, 88, 3, 20 }
	std::sort(v.begin(), v.end(), std::greater<int>());
	std::vector<int>::iterator it = std::unique(v.begin(), v.end());
	v.erase(it, v.end());
	for (int a : v)
		pq.push(a);
	do
	{
		std::cout << pq.top() << " ";
		pq.pop();
	} while (pq.size());
	//test if the algo for finding the top 3 num work
	//forming the big vector 
	std::cout << "\n\n testing the algo";
	std::priority_queue<int> pq_l;
	v.clear();
	v.resize(10000);
	for (int i = 0; i < 10000; i = i + 1)
		v[i] = (rand() % 10000);
	int cnt = 3;
	startTimer();
	for (int a : v)
		pq_l.push(a);
	do
	{
		std::cout << pq_l.top() << " ";
		pq_l.pop();
		cnt = cnt - 1;
	} while (cnt > 0);
	std::cout << "\nTime take for without algo :" << getTimer() <<" ms\n";
	do
		pq_l.pop();
	while (pq_l.size());
	std::priority_queue<int, std::vector<int>, std::greater<int>> pqm;
	//just insert only 3
	logr("testing logger");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	logr("some more");
	startTimer();
	for (int i = 0; i < 3; i = i + 1)
		pqm.push(v[i]);
	for (size_t i = 3; i < v.size(); i++)
	{
		pqm.push(v[i]);
		pqm.pop();
	}
	cnt = 3;
	do
	{
		std::cout << pqm.top() << " ";
		pqm.pop();
		cnt = cnt - 1;
	} while (cnt > 0);
	std::cout << "\nTime take for algo :" << getTimer() << " ms\n";

	//now with the algo
	std::cout << std::endl;
}
/*
	map, multimap, set, multiset, 
]*/
void try_algo_associativecontainer(void)
{
	std::unordered_set<int> uni = { 20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3, 66};
	std::set<int> s2 = { 20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3, 66 };

	std::unordered_set<vertex, vertexhash> vertset;
	for (auto a : s2)
		std::cout << a << " ";
	std::cout<<std::endl;
	std::unordered_set<int>::iterator it = std::find(uni.begin(), uni.end(), 3);
	std::unordered_set<int>::iterator it2 = uni.find(3);

}
void try_partition(void)
{
	//partition ostream_iterator
	std::deque<int> idq = { 20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };
	std::deque<int>::iterator itpiv, imid1, imid2;
	itpiv = std::next(idq.begin(), std::distance(idq.begin(), idq.end()) / 2);
	int pivot = *itpiv;
	std::copy(idq.begin(), idq.end(), std::ostream_iterator<int32_t>(std::cout, " "));
	std::cout << "\n";
	itpiv = std::partition(idq.begin(), idq.end(), [pivot](const int val) {return(val < pivot); });
	std::copy(idq.begin(), idq.end(), std::ostream_iterator<int32_t>(std::cout, " "));
	if (std::is_partitioned(idq.cbegin(), idq.cend(), [pivot](const int val) {return(val < pivot); }))
	{
		std::cout << "\n";
		std::copy(idq.begin(), itpiv, std::ostream_iterator<int32_t>(std::cout, " "));
		std::cout << "*";
		std::copy(itpiv, idq.end(), std::ostream_iterator<int32_t>(std::cout, " "));
	}
	std::cout << "\nPartition point :" << *(std::partition_point(idq.begin(), idq.end(), [pivot](const int val) {return(val < pivot); }))<<"\n";
}
void nth_element(void)
{	//nth_element
	std::vector<int32_t> v = { 20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };
	std::forward_list<int32_t> fl;
	for (auto a : v)
		fl.push_front(a);
	std::forward_list<int32_t>::iterator fit = fl.begin();
	std::vector<int32_t>::iterator vit = v.begin() + 5;
	std::nth_element(v.begin(), vit, vit + 5, std::less<int32_t>());

	std::copy(v.begin(), v.end(), std::ostream_iterator<int32_t>(std::cout, " "));
	std::cout << std::endl;
}
//binary_search
void binarysearch(void)
{
	std::vector<int32_t> v = { 20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };
	std::sort(v.begin(), v.end(), std::greater<int32_t>());
	//binary_search default uses <
	if (std::binary_search(v.begin(), v.end(), -78, std::greater<int32_t>()))
		std::cout << "binary_search found :" << -78;

	std::cout << std::endl;
}
/*
	reverse - bidirectional iterator
*/
void reverse_rotate(void)
{
	std::forward_list<int32_t> fl = { 20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };
	std::array<int32_t, 23> ar = { 20, -89, 45, 6, -4, -3, -78, 2, 67, 4, -30, 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };
	std::list<int32_t> lst = { 20, -89, 45, 6, -4, -3, -78, 2, 67, 4, -30, 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };

	//std::reverse(fl.begin(), fl.end());
	std::reverse(ar.begin(), ar.end());
	for (auto a : ar)
		std::cout << a << " ";
	//rotate
	std::cout << "\nstd::rotate..............\n";
	std::list<int32_t>::iterator itf = lst.begin();
	std::advance(itf, 5);
	std::rotate(lst.begin(), itf, lst.end());
	for (int32_t i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
	std::list<int32_t>::reverse_iterator rtf = lst.rbegin();
	std::advance(rtf, 5);
	std::rotate(lst.rbegin(), rtf, lst.rend());
	for (int32_t i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
}
void set_algo(void)
{
	//std::includes will work only with sorted list
	std::unordered_multiset <int32_t, hashint32, cmpint32> is = { 20, -89, 45, 6, -4, -3, -78, 2, 67, 4, -30, 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6 };	
	std::unordered_multiset<int32_t, hashint32, cmpint32> sub = { 90, 6, -78, 33, 10 };
	std::list<int32_t> lst = { 20, -89, 45, 6, -4, -3, -78, 2, 67, 4, -30, 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6, 77, -30, 4, 91, 4 };
	std::list<int32_t> needle = { -3, -78, 2, 67, 4 };
	bool bIncluded = false;
	try
	{
		//bool bincluded = std::includes(is.begin(), is.end(), sub.begin(), sub.end(), std::greater<int32_t>()); this will trow exception
		lst.sort();
		lst.unique();
		needle.sort();
		bIncluded = std::includes(lst.begin(), lst.end(), needle.begin(), needle.end());
	}
	catch (std::exception & e)
	{
		std::cout << "Exception :" << e.what();
	}
	//std::merge
	std::vector<int32_t> v1 = { 20, -89, 45, 6, -4, -3, -78, 2, 67, 4, -30, 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6, 77, -30, 4, 91, 4 };
	std::vector<int32_t>v2 = { 11, 5, 19, 7,  6};
	std::list<int32_t> v3;
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::front_insert_iterator<std::list<int32_t>>(v3));
	std::cout << std::endl;
}
bool predfind_if2(double b, vertex a)
{
	return(a.x == b);
}
bool predfind_if(vertex a, double b) 
{
	return(a.x == b);
}
void morealgo(void)
{
	//find_if
	std::vector<int32_t> v1 = { 20, -89, 45, 6, -4, -3, -78, 2, 67, 4, -30, 231, 355, 228, 226, -56, -400, 100, 34, 3, 45, 34, 6, 77, -30, 4, 91, 4 };
	std::vector<vertex> vv = { {1.2, 3.1, 5}, {1.2, 3.3, 5}, {1.5, 3.1, 5.7} };
	double d = 1.2;
	cmpfindif cmpf;
	std::vector<vertex>::iterator it;
	vertex a = { 1.4, 1.3, 2.3 };
	auto f1 = std::bind(predfind_if, std::placeholders::_1, d);
	//using return of std::bind()
	it = std::find_if(vv.begin(), vv.end(), f1);
	std::cout << it->x << it->y << "\n";
	//using lamda
	it = std::find_if(vv.begin(), vv.end(), [d](vertex a) {return(a.x == d); });
	std::cout << it->x << it->y << "\n";
	//using std::bind with functor
	std::vector<vertex>::iterator it2 = std::find_if(vv.begin(), vv.end(), std::bind(cmpf, std::placeholders::_1, d));
	std::cout << it->x << it->y << "\n";
	f1(a, 1.2);
	
	std::cout << std::endl;
}