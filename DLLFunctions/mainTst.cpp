#include <climits>
#include <iostream>
#include <string>

using namespace std;

#include "main.cpp"

int main() {

  ListD<int> *lst1 = new ListD<int>;
  int j = 1;
  for (int i = 10; i >= 0; i--) 
  {
   lst1->Insert(i, j);
    j++;
  }
  
  lst1->PrintForward();
  cout << endl;
  lst1->Sort();
  lst1->PrintForward();
}