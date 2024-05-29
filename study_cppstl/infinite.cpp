#include <iostream>


#include "learn.h"
#include "infinite.h"

void call_somefunc_infi(void)
{
	_derv1* pd1;
	pd1 = new _derv1();
	somefunc_infi(pd1);


	delete pd1;
}
void somefunc_infi(_base* pb)
{
	if (pb != nullptr)
		pb->show();
}
/*
Given two independently sorted(ascending order) singly linked lists write a function that will merge these two lists into one while preserving the sort order and return the head pointer of the merged list. A node in the list has int data.

Input :
List1 : 10 -> 40 -> 70
List2 : 20 -> 30 -> 80 -> 90

Output :
10 -> 20 -> 30 -> 40 -> 70 -> 80 -> 90
*/

_node* mergelist(_node* h1, _node* h2)
{
	_node* tail = nullptr;
	_node* head = nullptr;

	if (h1->n >= h2->n)
	{
		tail = head = h2;
		h2 = h2->pnext;
	}
	else
	{
		tail = head = h1;
		h1 = h1->pnext;
	}
		

	while ((h1 != nullptr) && (h2 != nullptr))
	{
		if (h1->n >= h2->n)
		{
			tail->pnext = h2;
			h2 = h2->pnext;
		}
		else
		{
			tail->pnext = h1;
			h1 = h1->pnext;
		}
		tail = tail->pnext;
	}
	if (h1 == nullptr)
		tail->pnext = h2;
	else
		tail->pnext = h1;
	return(head);
}