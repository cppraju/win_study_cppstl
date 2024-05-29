#pragma once


//print fibo series of n numbers
void printfibo(int n, int first, int last);

//print fibo nth number
void fibonthnum(int n);

//merge two link list
typedef struct _node
{
	_node* pnext = nullptr;
}NODE;
void mergelist(NODE* pA, NODE* pB);

//find if a word is palindrome
bool ispalindrome(char* str);

