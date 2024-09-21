
#include <iostream>

using namespace std;

// prototype for the function
int* getLocation(int arr[3][4], int target)
{
   
    static int location[2]; // STATIC NEEDDED _ LOSING DATA IN MAIN

    // we get to sorting
    int columns = 4;
    int rows = 3;

    int start = 0;
    int end = rows * columns - 1; // we know the size of the matrix is M * N - 1 for end of array marker


    while (start <= end)   // working from outer points, once they are equal or pass eachother - we are done sorting through array
    {
        int midPos = start + (end - start) / 2;
        int midVal = arr[midPos / columns][midPos % columns];

        if (midVal == target) // if found
        {
            location[0] = (midPos / columns);
            location[1] = (midPos % columns);  // return where we are at now

            return location;
        }
        else if (midVal < target)
        {
            start = midPos + 1;// now we move onto the left half since target is less
        }
        else
        {
            end = midPos - 1; // look at the latter half
        }
    }

    location[0] = -1;
    location[1] = -1;

    // if we dont find the target
    return location;
}

int main()
{
    // filled up 2D array
    int matrix[3][4] = { {1,2,3,4},{5,6,7,8},{8,10,11,12} };

    int target = 7;

    int* spot = getLocation(matrix, target);

    // output the final spot to console
    if (spot[0] != -1)
    {
        cout << "Target found at (" << spot[0] << ", " << spot[1] << ")" << endl;
    }
    else
        cout << "Target not found";

    return 0;
}
