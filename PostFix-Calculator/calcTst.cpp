/*
Name: Fady Youssef
Class: CPSC 122, Section 1
Date Submitted: April 24, 2024
=Description: Part 2 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char *argv[]) {
  
  Calc *C = new Calc(argv[1]);
  int result = C->Evaluate();

  C->DisplayInFix();
  C->DisplayPostFix();
  cout << "Evaluation: " << result << endl;

  delete C;
  return 0;
}
