#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// function prototype 
bool IsAllUnique(string s);

int main()
{
	string in;

	cout << "Enter a string of text: ";
	getline(cin, in);

	// since we dont want to have to worry about caps
	transform(in.begin(), in.end(), in.begin(), ::toupper);

	bool result;

	result = IsAllUnique(in);

	if (result == 0)
		cout << "False";
	else
		cout << "True";

	
}


bool IsAllUnique(string s)
{
	char current; // to hold the active char we are checking
	
	for (int count = 0; count < s.length(); count++)
	{
		// set the current element to the target
		current = s[count];
		int running = 0;

		// check to see if there is more than one of this element
		for (int i = 0; i < s.length(); i++)
		{
			
		if (current == s[i] && !isspace(current)) // if we have a white space, we dont care about duplications 
			{
				running++;
				if (running > 1)
				{
					return false;
				}
			}
			else
			{

			}
		}
	}

	return true;
}
