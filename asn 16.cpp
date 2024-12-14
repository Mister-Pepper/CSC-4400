#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Node structure for Binary Search Tree
struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val) 
    {
        data = val;
        left = right = nullptr;
    }
};

// binary search Tree class
class BinarySearchTree 
{
private:
    Node* root;

    // inserting a node
    Node* insert(Node* root, int value) 
    {
        if (root == nullptr) 
        {
            return new Node(value);
        }
        if (value < root->data) 
        {
            root->left = insert(root->left, value);
        }
        else 
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    // jto print the tree
    void inorder(Node* root) 
    {
        if (root != nullptr) 
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    // find the minimum value node
    Node* findMin(Node* root) 
    {
        while (root->left != nullptr) 
        {
            root = root->left;
        }
        return root;
    }

    // delete a node
    Node* deleteNode(Node* root, int value) 
    {
        if (root == nullptr) return root;

        // Find the node to be deleted
        if (value < root->data) 
        {
            root->left = deleteNode(root->left, value);
        }
        else if (value > root->data) 
        {
            root->right = deleteNode(root->right, value);
        }
        else 
        {
            // Node with only one child or no child
            if (root->left == nullptr) 
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) 
            {
                Node* temp = root->left;
                delete root;

                return temp;
            }

            // node wth two children: get  successor
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // search for a node
    bool search(Node* root, int value) 
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->data == value)
        {
            return true;
        }
        if (value < root->data)
        {
            return search(root->left, value);
        }
        // if noting else pans out
        return search(root->right, value);
    }

public:
    BinarySearchTree() 
    {
        root = nullptr;
    }

    // insert a new value
    void insert(int value) 
    {
        root = insert(root, value);
    }

    // Delete 
    void deleteValue(int value) 
    {
        root = deleteNode(root, value);
    }

    // Search 
    bool search(int value) 
    {
        return search(root, value);
    }

    // Print the tree 
    void printTree() 
    {
        inorder(root);
        cout << endl;
    }
};

int main() 
{
    srand(time(0)); // gotta seed time

    BinarySearchTree bst;

    // Randomly insert 10 non-repeated numbers from 0 to 9 (task 1)
    vector<int> numbers;
    for (int i = 0; i < 10; i++) 
    {
        numbers.push_back(i); // add
    }
    random_shuffle(numbers.begin(), numbers.end());

    // just output stuff to the console
    cout << "**** Task 1: Inserting 10 Random Numbers into the BST ****" << endl;
    for (int i = 0; i < 10; i++) 
    {
        bst.insert(numbers[i]);
    }

    // show what the tree hsa
    cout << "Tree after insertion: ";
    bst.printTree();

    // delete 3 randomly selected numbers (task 2)
    vector<int> deleteNumbers = { numbers[0], numbers[1], numbers[2] };
    cout << "\n**** Task 2: Deleting 3 Random Numbers from the BST ****" << endl;
    cout << "Numbers to be deleted: ";

    for (int i = 0; i < 3; i++) 
    {
        cout << deleteNumbers[i] << " ";
        bst.deleteValue(deleteNumbers[i]);
    }
    cout << "\nTree after deletion: ";
    bst.printTree();

    // ssearch for 3 random numbers (task 3)
    vector<int> searchNumbers = { numbers[3], numbers[4], numbers[5] };
    cout << "\n**** Task 3: Searching for 3 Random Numbers in the BST ****" << endl;

    for (int i = 0; i < 3; i++) 
    {
        cout << "Searching for " << searchNumbers[i] << ": ";
        if (bst.search(searchNumbers[i])) 
        {
            cout << "Found!" << endl;
        }
        else 
        {
            cout << "Not Found!" << endl;
        }
    }

    cout << endl;

    return 0;
}
