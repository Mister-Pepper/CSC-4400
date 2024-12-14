#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// hashtable class
class HashTable
{
private:
    static const int size = 10;  // Table size
    int keys[size];
    int values[size];

public:
    HashTable()
    {
        // initialize all the arrays with -1 to signify start value
        for (int count = 0; count < size; count++)
        {
            keys[count] = -1;
            values[count] = -1;
        }
    }

    // simple hash function
    int hash(int key)
    {
        return key % size;
    }

    void insert(int key, int val)
    {
        int index = hash(key);
        int startIndex = index; // Track the starting index

        // linear probing with detection for full table
        while (keys[index] != -1) // check if the slot is empty
        {
            if (keys[index] == key) // if key already exists
            {
                values[index] = val; // update the value
                cout << "Updated [" << key << ", " << val << "] at index " << index << endl;
                return;
            }

            index = (index + 1) % size; // move to the next slot

            // If we've looped back to the start, the table is full
            if (index == startIndex)
            {
                cout << "Table is full, can't insert!" << endl;
                return;
            }
        }

        // If an empty slot is found
        keys[index] = key;
        values[index] = val;
        cout << "Inserted [" << key << ", " << val << "] at index " << index << endl;
    }

    void remove(int key)
    {
        int index = hash(key);
        int startIndex = index; // Track the starting index

        // search for the key
        while (keys[index] != -1) // check if the slot is empty
        {
            if (keys[index] == key) // key found
            {
                keys[index] = -1; // remove the key
                values[index] = -1; // remove the value
                cout << "Key " << key << " removed at index " << index << endl;
                return;
            }

            index = (index + 1) % size; // move to the next slot

            // If we've looped back to the start, the key was not found
            if (index == startIndex)
            {
                cout << "Key " << key << " not found..." << endl;
                return;
            }
        }
    }

    int search(int key)
    {
        int index = hash(key);

        while (keys[index] != -1) // check if the index is empty?
        {
            // if not
            if (keys[index] == key)
            {
                return values[index]; // return value if found
            }
            index = (index + 1) % size; // move to the next slot
        }

        return -1; // return -1 if not found
    }

    void display()
    {
        cout << "Hash Table: ";
        for (int count = 0; count < size; count++)
        {
            if (keys[count] != -1) // if the index isn't empty
            {
                cout << "[" << keys[count] << ", " << values[count] << "] "; // display key-value pair
            }
            else
            {
                cout << "[empty] "; // if slot is empty
            }
        }

        cout << endl;
    }
};

int main()
{
    srand(time(0)); // just seed rand function

    HashTable Table;

    // fill it up with 10 random functions
    for (int count = 0; count < 10; count++)  // Change this number as needed
    {
        int key = rand() % 101; // limit key to 100
        int value = rand() % 1001; // limit value to 1000

        // actually insert this
        Table.insert(key, value);
    }

    // now display after insert
    cout << "After insertion:" << endl;
    Table.display();

    // remove two keys
    Table.remove(5);
    Table.remove(10);

    // now display the updated table
    cout << "After removal:" << endl;
    Table.display();

    // use search function for some keys
    int searchKey1 = 10;
    int searchKey2 = 20;

    cout << "When searching for key " << searchKey1 << ": " << Table.search(searchKey1) << endl;
    cout << "When searching for key " << searchKey2 << ": " << Table.search(searchKey2) << endl;

    return 0;
}
