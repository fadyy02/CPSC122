#include <iostream>
using namespace std;

#include "main.h"

int main() {
  // Create a new instance of ListT
  ListT lst;

  // Testing PutItemH function
  for (int i = 1; i <= 5; i++)
    lst.PutItemH(i);

  // Testing GetItemH function
  cout << "Item at the head of the list: " << lst.GetItemH() << endl;

  // Testing PutItemT function
  for (int i = 6; i <= 10; i++)
    lst.PutItemT(i);

  // Testing GetItemT function
  cout << "Item at the tail of the list: " << lst.GetItemT() << endl;

  // Testing DeleteItemH function
  lst.DeleteItemH();
  cout << "List after deleting item at the head:" << endl;
  lst.Print();

  // Testing DeleteItemT function
  lst.DeleteItemT();
  cout << "List after deleting item at the tail:" << endl;
  lst.Print();

  // Testing FindItem function
  cout << "Occurrences of 3 in the list: " << lst.FindItem(3) << endl;

  // Testing DeleteItem function
  int deletedCount = lst.DeleteItem(5);
  cout << "Deleted " << deletedCount << " nodes with value 5." << endl;
  cout << "List after deleting nodes:" << endl;
  lst.Print();

  // Testing IsEmpty and GetLength functions
  cout << "Is the list empty? " << (lst.IsEmpty() ? "Yes" : "No") << endl;
  cout << "Length of the list: " << lst.GetLength() << endl;

  return 0;
}

