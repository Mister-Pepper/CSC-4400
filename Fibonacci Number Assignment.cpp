#include <iostream>

using namespace std;


int main()
{
    int in;

    cout << "Enter a number: ";
    cin >> in;

    cout << endl;


    int leftNum = 0;
    int rightNum = 1;
    int tempNum;
    for (int count = 0; count < in; count++)
    {
        tempNum = leftNum + rightNum;
        leftNum = rightNum;
        rightNum = tempNum;
    }
    // 0,1,1,2,3,5,8,13,21,34
    cout << "Fibonacci(" << in << ") = " << tempNum << endl << endl;

    cout << "The algorithm iterated " << in << " times..." << endl;

    return 0;
}
