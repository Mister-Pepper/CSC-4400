// Shell Sort & Quick Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Functio prototypes
void shellSort(int arr[], int size);
void quickSort(int arr[], int lo, int hi);

int main()
{
    // declare array
    int const numbers = 10000;
    int arr[numbers];

    // seed for rand
    srand(static_cast<unsigned int>(time(0)));

    // fill up with random values
    for (int count = 0; count < numbers; count++)
    {
        arr[count] = rand() % 10000; // Random numbers between 0 and 9999
    }

    // copy the array to test it in both sorting algo functions
    int shellTestArray[numbers];

    for (int count = 0; count < numbers; count++)
    {
        shellTestArray[count] = arr[count];
    }

    // test time for the shell test function
    auto start = chrono::high_resolution_clock::now();
    shellSort(shellTestArray, numbers);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> shellTime = end - start;
    cout << "Shell sort time was " << shellTime.count() << " MS to sort the array" << endl;


    // now we do the quicksort array
    int quickArr[numbers];

    // copy over values again
    for (int count = 0; count < numbers; count++)
    {
        quickArr[count] = arr[count];
    }

    // time the algo
    auto startQuick = chrono::high_resolution_clock::now();
    quickSort(quickArr, 0, numbers - 1);
    auto endQuick = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> quickTime = endQuick - startQuick;
    cout << "Quick Sort time was " << quickTime.count() << " MS to sort the array" << endl;
}

/*** Function Bodies ***/

void shellSort(int arr[], int size)
{
    // deal with gaps
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int count = gap; count < size; count++)
        {
            int temp = arr[count];


            // shift earlier elements
            int i;

            for (i = count; i >= gap && arr[i - gap] > temp; i -= gap)
            {
                arr[i] = arr[i - gap];
            }

            // put temp into its correct location 
            arr[i] = temp;
        }
    }
}

void quickSort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        // set pivot, we will use the last element
        int pivot = arr[hi];
        int i = lo - 1;

        //partition
        for (int count = lo; count < hi; count++)
        {
            if (arr[count] < pivot)
            {
                i++;
                swap(arr[i], arr[count]);
            }
        }
        swap(arr[i + 1], arr[hi]);

        int midpt = i + 1;


        //recursive part of the function
        quickSort(arr, lo, midpt - 1);
        quickSort(arr, midpt + 1, hi);

    }

}