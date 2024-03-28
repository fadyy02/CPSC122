#include <iostream>
using namespace std;

#include "main.h"

// Main function where the program starts execution
int main()
{
    // Create a new list using dynamic memory allocation
    List* lst1 = new List;

    // Create a static list
    List lst;

    // Check if the static list is empty
    cout << "Is the list empty? (Test 1)" << endl;
    cout << "Expected: 1 (true)" << endl;
    cout << lst1->IsEmpty() << endl; // Output: 1 (true)
    cout << endl;

    // Check the length of the static list
    cout << "Length of the list (Test 1)" << endl;
    cout << "Expected: 0" << endl;
    cout << lst1->GetLength() << endl; // Output: 0
    cout << endl;

    // Add items 1 to 5 to the static list
    cout << "Adding items 1 to 5 to the static list" << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    for (int i = 1; i < 6; i++)
        lst.PutItemH(i);
    lst.Print();

    // Add items 1 to 5 to the dynamic list
    cout << "Adding items 1 to 5 to the dynamic list" << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    for (int i = 1; i < 6; i++)
        lst1->PutItemH(i);
    lst1->Print();

    // Check if the dynamic list is empty
    cout << "Is the list empty? (Test 2)" << endl;
    cout << "Expected: 0 (false)" << endl;
    cout << lst1->IsEmpty() << endl; // Output: 0 (false)
    cout << endl;

    // Check the length of the dynamic list
    cout << "Length of the list (Test 2)" << endl;
    cout << "Expected: 5" << endl;
    cout << lst1->GetLength() << endl; // Output: 5
    cout << endl;

    // Get the item at the head of the dynamic list
    cout << "Get the item at the head of the list" << endl;
    cout << "Expected: 5" << endl;
    cout << lst1->GetItemH() << endl; // Output: 5
    cout << endl;

    // Print the dynamic list
    cout << "Print the list (Test 2)" << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    lst1->Print();
    cout << endl;

    // Delete the item at the head of the dynamic list
    cout << "Delete the item at the head of the list" << endl;
    cout << "Expected: 4 3 2 1" << endl;
    lst1->DeleteItemH();
    lst1->Print();
    cout << endl;

    // Find occurrences of items in the dynamic list
    cout << "Find occurrences of items in the list" << endl;
    cout << "Expected: 5 3 1 -1" << endl;
    lst1->Print();
    cout << "Occurrences of 5: " << lst1->Find(5) << endl;
    cout << "Occurrences of 3: " << lst1->Find(3) << endl;
    cout << "Occurrences of 1: " << lst1->Find(1) << endl;
    cout << "Occurrences of 0: " << lst1->Find(0) << endl;
    cout << endl;

    // Delete items from the dynamic list
    delete lst1;
    cout << "Delete items from the list" << endl;
    List* lst2 = new List;
    cout << "Deleting target from various positions" << endl;
    cout << "Expected: 2 0 2 3 2 0 3" << endl;
    lst2->PutItemH(3);
    lst2->PutItemH(2);
    lst2->PutItemH(0);
    lst2->PutItemH(2);
    lst2->Print();
    cout << lst2->DeleteItem(2) << endl;
    cout << endl;
    lst2->Print();
    cout << endl;

    cout << "Expected: 2 1 0 3" << endl;
    lst2->PutItemH(2);
    lst2->PutItemH(2);
    lst2->PutItemH(1);
    cout << lst2->DeleteItem(2) << endl;
    cout << endl;
    lst2->Print();
    cout << endl;

    cout << "Expected: 1 1 0" << endl;
    cout << lst2->DeleteItem(3) << endl;
    cout << endl;
    lst2->Print();

    cout << "Expected: 2 0" << endl;
    lst2->DeleteItem(0);
    lst2->DeleteItem(3);
    cout << endl;
    lst2->PutItemH(1);
    lst2->PutItemH(0);
    cout << lst2->DeleteItem(1) << endl;
    cout << endl;
    lst2->Print();
    delete lst2;

    return 0; // End the program
}
