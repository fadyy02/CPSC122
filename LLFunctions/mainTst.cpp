#include <iostream>
#include "main.h"

using namespace std;

  int main() {
    // Create a static list
    ListT lst;
    
    lst.PutItemH(1);
    lst.PutItemT(2);
    lst.PutItemT(2);
    lst.PutItemH(2);
    lst.Print();
    cout << endl;
    lst.DeleteItem(2);
    lst.Print();
    
    

   /*cout << "Test PutItemH and Print" << endl;
    cout << "Correct if output is 4, 3, 2, 1, 0 on subsequent lines" << endl;
    for (int i = 0; i < 5; i++)
      lst.PutItemH(i);
    lst.Print();

    cout << endl;

    // Check if the static list is empty
    cout << "Is the list empty? (Test 1)" << endl;
    cout << "Expected: 1 (true)" << endl;
    cout << lst.IsEmpty() << endl; // Output: 1 (true)
    cout << endl;

    // Check the length of the static ListT
    cout << "Length of the ListT (Test 1)" << endl;
    cout << "Expected: 5" << endl;
    cout << lst.GetLength() << endl; // Output: 5
    cout << endl;

    // Add items 1 to 5 to the static ListT
    cout << "Adding items 1 to 5 to the static ListT" << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    for (int i = 1; i < 6; i++)
      lst.PutItemH(i);
    lst.Print();

    // Create a new dynamic list
    ListT lst1;

    // Add items 1 to 5 to the dynamic ListT
    cout << "Adding items 1 to 5 to the dynamic ListT" << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    for (int i = 1; i < 6; i++)
      lst1.PutItemH(i);
    lst1.Print();

    // Check if the dynamic ListT is empty
    cout << "Is the ListT empty? (Test 2)" << endl;
    cout << "Expected: 0 (false)" << endl;
    cout << lst1.IsEmpty() << endl; // Output: 0 (false)
    cout << endl;

    // Check the length of the dynamic ListT
    cout << "Length of the ListT (Test 2)" << endl;
    cout << "Expected: 5" << endl;
    cout << lst1.GetLength() << endl; // Output: 5
    cout << endl;

    // Get the item at the head of the dynamic ListT
    cout << "Get the item at the head of the ListT" << endl;
    cout << "Expected: 5" << endl;
    cout << lst1.GetItemH() << endl; // Output: 5
    cout << endl;

    // Print the dynamic ListT
    cout << "Print the ListT (Test 2)" << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    lst1.Print();
    cout << endl;

    // Delete the item at the head of the dynamic ListT
    cout << "Delete the item at the head of the ListT" << endl;
    cout << "Expected: 4 3 2 1" << endl;
    lst1.DeleteItemH();
    lst1.Print();
    cout << endl;

    // FindItem occurrences of items in the dynamic ListT
    cout << "FindItem occurrences of items in the ListT" << endl;
    cout << "Expected: 5, 1, 1, 0" << endl;
    cout << "Occurrences of 5: " << lst1.FindItem(5) << endl;
    cout << "Occurrences of 3: " << lst1.FindItem(3) << endl;
    cout << "Occurrences of 1: " << lst1.FindItem(1) << endl;
    cout << "Occurrences of 0: " << lst1.FindItem(0) << endl;
    cout << endl;
    */
  return 0;
}