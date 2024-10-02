// Selection Sort Vs Bubble Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

// prototype
int* RandomizedArray(int size);


int main()
{
    cout << "Enter a size for an array: ";
    int input;
    cin >> input;


    int* ptr; // this will be pointing towards the returned array
    int* ptr2 = new int[input];

    // seed random function
    srand(time(0));

    ptr = RandomizedArray(input);

    //copy over values
    for (int count = 0; count < input; count++)
    {
        ptr2[count] = ptr[count];
    }


  /*  cout << "This is the first array before using bubble sort: ";
    cout << endl;
    for (int count = 0; count < input; count++)
    {
        cout << ptr[count] << " ";
    }
    cout << endl << endl;*/

    // using bubble sort for the first array
    auto startBubble = chrono::high_resolution_clock::now(); // Start timing

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input -1 -i; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(ptr[j], ptr[j + 1]);
            }
        }

    }
    auto endBubble = chrono::high_resolution_clock::now(); // End timing
    chrono::duration<double, std::milli> durationBubble = endBubble - startBubble; // Calculate duration in MS

  /*  cout << "This is the first array before using selection sort: ";
    cout << endl;
    for (int count = 0; count < input; count++)
    {
        cout << ptr2[count] << " ";
    }

    cout << endl << endl;*/


    // using selection sort for the second array 
    auto startSelection = chrono::high_resolution_clock::now(); // Start timing

    for (int count = 0; count < input; count++)
    {
        int smallestIndex = count;

        for (int j = count + 1; j < input; j++)
        {
            if (ptr2[j] < ptr2[smallestIndex])
            {
                smallestIndex = j;
            }

            // get to swapping
            int temp = ptr2[count];
            ptr2[count] = ptr2[smallestIndex];
            ptr2[smallestIndex] = temp;
        }
    }
    auto endSelection = chrono::high_resolution_clock::now(); // End timing
    chrono::duration<double, std::milli> durationSelection = endSelection - startSelection; // Calculate duration in MS

    cout << "Sorting a random array size of " << input << " took Bubble Sort " << durationBubble.count() << "MS to complete.";
    cout << endl;
    
    cout << endl << endl;

    cout << "Sorting a random array size of " << input << " took Selection Sort " << durationSelection.count() << "MS to complete.";
    cout << endl;
   

    // free up the memory 
    delete[] ptr;
    delete[] ptr2;

}

int* RandomizedArray(int size)
{
    // declare the dynamic array
    int* list = new int[size];

    // fill up the array
    for (int count = 0; count < size; count++)
    {
        // random number generated
        int temp = (rand() % 100001);

        list[count] = temp;
    }

    return list;
}