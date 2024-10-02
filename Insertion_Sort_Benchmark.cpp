

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <set>
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
    int* ptr3 = new int[input];

    // seed random function
    srand(time(0));

    ptr = RandomizedArray(input);

    //copy over values for selection sort
    for (int count = 0; count < input; count++)
    {
        ptr2[count] = ptr[count];
    }

    //copy over values for insertion sort
    for (int count = 0; count < input; count++)
    {
        ptr3[count] = ptr[count];
    }

      // using bubble sort for the first array
    auto startBubble = chrono::high_resolution_clock::now(); // Start timing

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input - 1 - i; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(ptr[j], ptr[j + 1]);
            }
        }

    }
    auto endBubble = chrono::high_resolution_clock::now(); // End timing
    chrono::duration<double, std::milli> durationBubble = endBubble - startBubble; // Calculate duration in MS


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

    // using insertion sort for the 3rd array
    auto startInsertion = chrono::high_resolution_clock::now(); // Start timing

    int i = 0;
    int j = 0;
    int temp = 0;

    for (int count = 1; count < input; ++count)
    {
        int num = ptr3[count];
        int j = count - 1;

        // move around elements
        while (j >= 0 && ptr3[j] > num)
        {
            ptr3[j + 1] = ptr3[j];

            j = j - 1;
        }

        ptr3[j + 1] = num;
    }
    
    auto endInsertion = chrono::high_resolution_clock::now(); // End timing
    chrono::duration<double, std::milli> durationInsertion = endInsertion - startInsertion; // Calculate duration in MS

    cout << "Sorting a random array size of " << input << " took Bubble Sort " << durationBubble.count() << "MS to complete.";
    cout << endl;

    cout << endl << endl;

    cout << "Sorting a random array size of " << input << " took Selection Sort " << durationSelection.count() << "MS to complete.";
    cout << endl;

    cout << endl << endl;

    cout << "Sorting a random array size of " << input << " took Insertion Sort " << durationInsertion.count() << "MS to complete.";
    cout << endl;


    // free up the memory 
    delete[] ptr;
    delete[] ptr2;
    delete[] ptr3;

}

int* RandomizedArray(int size)
{
    // declare the dynamic array
    int* list = new int[size];

    // set container to make sure we dont get those duplicated values
    set<int> checkedlist;

    // fill up the array
    for (int count = 0; count < size; count++)
    {
        // random number generated
        int temp = (rand() % 100001);

        // validate the value generated first before adding it to the array
        if (checkedlist.find(temp) == checkedlist.end()) // means we got through the entire array
        {
            list[count] = temp;

            checkedlist.insert(temp);

            count++;
        }

        list[count] = temp;
    }

    return list;
}
