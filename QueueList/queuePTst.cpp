#include <iostream>
using namespace std;

#include "queueP.h"

int main() {

  PQueue *que = new PQueue;
  for (int i = 1; i <= 10; i++)
    que->Enqueue(i);
  que->Print();
  cout << endl << endl << endl;
  que->Enqueue(5);
  que->Enqueue(5);
  que->Enqueue(5);
  que->Enqueue(1);
  que->Enqueue(0);
  que->Enqueue(50);
  que->Print();
  cout << endl;
  cout << "Length: " << que->GetLength() << endl;
  cout << endl;
  que->Dequeue(); // deletes only head, is this how its supposed to be?
  que->Print();
  cout << endl;
  cout << "Length: " << que->GetLength() << endl;
  delete que;

  return 0;
}
