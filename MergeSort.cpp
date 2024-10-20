// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

// function prototypes
void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main()
{
    // create an array of some random numbers
    int const numbers = 1000;
    int arr[numbers];

    // fill up with some random values
    srand(static_cast<unsigned int>(time(0)));  // seed

    for (int count = 0; count < numbers; count++)
    {
        arr[count] = rand() % 10000 + 1;    
    }

   // testing mergesort out now
    mergesort(arr, 0, numbers - 1);

    cout << "After Merge sort the array looks like: ";
    for (int count = 0; count < numbers; count++)
    {
        cout << arr[count] << " ";
    }

    cout << endl << endl;
}

// function bodies
void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        
        // sort halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        // combine the halves whenever this all comes back when base case hits
        merge(arr, left, mid, right);
        
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    // while there are still elements in the half
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            int num = arr[j];
            int index = j;

            // shift elements
            while (index != i)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[i] = num;

            // updates trackers
            i++;
            mid++;
            j++;
        }

    }

}