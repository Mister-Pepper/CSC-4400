// Recursive Fibonacci Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// function prototypes
int makeFibNum(int num);

int main()
{
	int n = 6;

	int counter = 0;

	int answer = makeFibNum(n);


	cout << "F(" << n << ") = " << answer << endl;

	return 0;
}

// function bodies
int makeFibNum(int num)
{
	/*** BASE CASES  ***/

	if (num == 0) // since first two vals of fib sequence are 1 & 0;
	{
		return 0;
	}

	if (num == 1)
	{
		return 1;
	}
	
	/*** RECURSIVE CASE  ***/

	return (makeFibNum(num - 1) + makeFibNum(num - 2));
	
}
