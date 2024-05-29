/******************************************************************************

 Online C++ Compiler.
 Code, Compile, Run and Debug C++ program online.
 Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <future>
#include <functional>
#include <map>
#include <thread>
#include <typeinfo>

#include "learn.h"

#include "main.h"

//#include <initializer_list>

using namespace std;
single * single::sp = NULL;
single single::sp3;

/*
	compute minimum currency change
*/
void minchange(long s, change &c)
{
    long rem;
    c.b10 = s / 10;
    rem = s % 10;
    if(rem % 2 == 0)
        c.c2 = rem / 2;
    else
    {
        c.b5 = rem / 5;
        rem = rem % 5;
        c.c2 = rem / 2;
    }
	 rem = rem % 2;
    cout<<"tot: "<<s<<" 10: "<<c.b10<<" 5: "<<c.b5<<" 2: "<<c.c2<<" rem: "<<rem<<endl;
}

void stringencryption(void)
{
 string s, sout, st;

  string::iterator sit;

  cin >> s;
  int bit = -1, oldbit = -1;
  bool bChange = true;
  unsigned char cmask = 64;
  for (sit = s.begin (); sit < s.end (); sit = sit + 1)
    {
      for (int i = 7; i > 0; i = i - 1)
	    {
	      bit = cmask == (cmask & *sit) ? 1 : 0;
    	  if (oldbit != bit)
     	      st = bit == 1 ? " 0 " : " 00 ";
   	      st = st + "0";
     	  oldbit = bit;
    	  sout += st;
    	  cmask = cmask >> 1;
		  st.erase();
	    }
	    cmask = 64;
	}
    cout << sout << endl;
}

/*
	This will locate the biggest group of consecutive numbers from a group of numbers 
*/
CNG GetBiggestGrp(void)
{
	CNG c;
	vector<int> arr;
	vector<CNG> argps;
	int ia[20] = {20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3};
	for(int i = 0; i < sizeof(ia)/sizeof(int); i = i + 1)
		arr.push_back(ia[i]);
	int n = arr.size();
	/*
		we will start with the largest grp possible that is 1 element less than the 
		arr size then gradually reduce till the grp size is of 2 elements. Store them
		and easily find the largest
	*/
	for(int grpsz = n - 1; grpsz > 1; grpsz = grpsz - 1)
	{
		for(int st = 0, end = st + grpsz - 1; end < n; st = st + 1, end = st + grpsz - 1)
		{
			CNG t;
			t.st = st;
			t.end = end;
			for(int i = st; i <= end; i = i + 1)
				t.val = t.val + arr[i];
			//done adding all the values in this group
			//compare and store if this value is bigger
			if(c.val < t.val)
				c = t;
		}
	}
	return(c);
}
/*
	Find a node in a tree
*/
bool findnode(tree *pn, int val, tree **pret)
{
	bool found = false;
	if(pn == NULL)
		return(false);
	if(pn->n == val)
	{
		*pret = pn;
		return(true);
	}
	found = findnode(pn->lf, val, pret);
	if(found)
		return(true);		//no need to search anymore
	found = findnode(pn->rt, val, pret);
	if(found)
		return(true);		//no need to search anymore
	return(found);
}
/*
Traverse the tree in inorder
*/
void inord(tree *ro)
{
	if(ro==NULL)
		return;
	else
	{
		inord(ro->lf);
		cout<<" "<<ro->n;
		inord(ro->rt);
		return;
	}
}
/*
	insert a node in a tree
*/
void insert(tree *ro,int val)
{
	while(ro!=NULL)
	{
		if((ro!=NULL)&&((ro->n)>(val)))
		{
			if(ro->lf==NULL)
			{
				ro->lf=new tree;
				if(ro->lf==NULL)
				{
					cout<<"Memory cannot be allocated !";
					fflush(stdin);
					return;
				}
				*(ro->lf)=tree(val);
				break;
			}
			ro=ro->lf;
		}
		if((ro!=NULL)&&((ro->n)<(val)))
		{
			if(ro->rt==NULL)
			{
				ro->rt=new tree;
				if(ro->rt==NULL)
				{
					cout<<"Memory cannot be allocated !";
					fflush(stdin);
					return;
				}
				*(ro->rt)=tree(val);
				break;
			}
			ro=ro->rt;
		}
		if((ro->n)==val)
		{
			cout<<"duplicate entry !";
			fflush(stdin);
			break;
		}
	}
}
/*A obj;
A createA(void)
{
	return(obj);
}
*/
void someA(A b)
{
	std::cout<<"Hello"<<std::endl;
}

void domainfreq(void)
{	
	std::string str[] = {"steve@gmail.com", "marriot@yahoo.com", "rajesh.jain@iiml.ac.in", "faculty.surname@iiml.ac.in", "srijan@gmail.com", "admin@iiml.ac.in"};
	std::vector<string> vs;
	for(std::string s : str)
		vs.push_back(s);
	std::map<std::string, int, compstr> mf;
	std::map<std::string, int, compstr>::iterator itm;
	for(std::string s : vs)
	{
		char buf[32], *pToken, *pContext;
		memset(buf, 0, sizeof(buf));
		strcpy_s(buf, sizeof(buf), s.c_str());
		pToken = strtok_s(buf, "@", &pContext);
		if(pContext != NULL)
			itm = mf.find(pContext);
		if(itm != mf.end())
			itm->second = itm->second + 1;
		else
			mf.emplace(std::make_pair(pContext, 1));
	}
	for(auto a : mf)
		std::cout<<a.first<<" "<<a.second<<std::endl;

}

int imain ()
{
/*	int ia[20] = {20, -89, 45, 6, -4 , -3, -78, 2, 67, 4, -30 , 231, 355, 228, 226, -56, -400, 100, 34, 3};
	tree *ro = new tree(10);
	for(int i = 0; i < 20; i = i + 1)
		insert(ro, ia[i]);
	inord(ro);
	cout<<endl;
	tree *pf = NULL;
	if(findnode(ro, -78, &pf))
		cout<<pf->getvalue()<<" "<<pf<<endl;
	cout<<endl;
	cout<<endl;
    for(int j = 11; j < 20; j = j + 1)
    {
        change d;
        minchange(j, d);
    }
	int B::*pm = &B::x;
	void (B::*pfn)(int) = &B::f;
	B *pobj;
	B tem;
	pobj = &tem;
	tem.*pm = 20;
	(pobj->*pfn)(30);

	someA(std::move(obj));
	auto x = [](int a)
	{
		std::cout<<"lambda function called"<<std::endl;
	};
	x(10);
	domainfreq();
	return 0;
	/*------------------------------------------------------------*/
//	A s = 100;
//	std::cout<<s;
//	caller();
	
//	somefunc2();

	return(0);
}

