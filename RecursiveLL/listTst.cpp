#include "list.h"
#include <iostream>

using namespace std;

int main() {
  List *lst1 = new List;
  // List lst;
  // int lst3 = [5,4,2,6,3,5];

  for (int i = 1; i <= 10; i++) {
    lst1->PutItemH(i);
  }

  cout << "\nPrint: " << endl;
  lst1->Print();
  cout << endl << endl;

  cout << "Print Reversed: " << endl;
  lst1->PrintRev();
  cout << endl << endl;

  cout << "Length of list: " << lst1->GetLength();
  cout << endl << endl;
  // delete lst1;
  return 0;
}

// make
//./main