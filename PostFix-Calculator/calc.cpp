#include "calc.h"
#include <cctype>  // Include cctype for isdigit and isalpha
#include <cstdlib> // Include cstdlib for exit function
#include <cstring>
#include <iostream>

using namespace std;

Calc::Calc(const char *argvIn) {
  stk = new Stack();

  int len = strlen(argvIn);
  inFix = new char[len + 1];   // Allocate memory for the infix expression
  postFix = new char[len + 1]; // Allocate memory for the postfix expression

  strcpy(inFix, argvIn); // Copy the input expression to the inFix member

  // Check for valid tokens and balanced parentheses
  if (!CheckTokens())
    cout << "Invalid token input\n";
  else
    cout << "Tokens Balanced\n";
  if (!CheckParens())
    cout << "Invalid parens input\n";
  else
    cout << "Parens Balanced\n";

  MakeValueTbl();   // Initialize the value table
  Parse();          // Parse the infix expression
  InFixToPostFix(); // Convert infix to postfix
}

Calc::~Calc() {
  delete[] inFix;    // Free memory allocated for infix expression
  delete[] postFix;  // Free memory allocated for postfix expression
  delete[] valueTbl; // Free memory allocated for value table
}

void Calc::MakeValueTbl() {
  valueTbl = new int[26]; // Allocate memory for value table (26 positions)
  for (int i = 0; i < 26; i++)
    valueTbl[i] = 0; // Initialize all positions to zero
}

int Calc::FindLast(int cur) {
  // Find the last digit in a digit string
  int last = cur;
  while (isdigit(inFix[last])) {
    last++;
  }
  return last - 1; // Return the index of the last digit
}

bool Calc::CheckParens() {
  bool bal = true; // Assume parentheses are balanced initially
  int i = 0;
  char ch = inFix[i];
  while (bal && ch != '\0') {
    if (ch == '(')
      stk->Push(ch); // Push '(' onto the stack
    else if (ch == ')') {
      if (!stk->IsEmpty())
        stk->Pop(); // Pop '(' from the stack
      else
        bal = false; // Unbalanced parentheses
    }
    i++;
    ch = inFix[i];
  }
  if (bal && stk->IsEmpty()) // Check if stack is empty (balanced)
    return true;
  return false;
}

bool Calc::CheckTokens() {
  // Check for valid tokens in the infix expression
  for (int i = 0; inFix[i] != '\0'; i++) {
    if (!(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' ||
          inFix[i] == '(' || inFix[i] == ')' ||
          ((isalpha(inFix[i]) && isupper(inFix[i]))) || isdigit(inFix[i]))) {
      cout << "Invalid Input\n";
      return false;
    }
  }
  return true;
}

void Calc::Parse() {
  MakeValueTbl(); // Initialize value table
  int i = 0;
  int j = 0;

  // Parse the infix expression
  while (inFix[i] != '\0') {
    if (isdigit(inFix[i])) {
      int num = 0;
      while (isdigit(inFix[i])) {
        num = num * 10 + (inFix[i++] - '0');
      }
      inFix[j++] = 'A' + valueIdx;
      valueTbl[valueIdx++] = num; // Store numeric value in value table
    } else {
      inFix[j++] = inFix[i++];
    }
  }
  inFix[j] = '\0'; // Add null terminator to the parsed infix expression
}

void Calc::InFixToPostFix() {
  char ch;
  int i = 0; // Add an index variable
  for (int j = 0; inFix[j] != '\0'; j++) {
    ch = inFix[j];
    if (isdigit(ch) || isalpha(ch)) {
      postFix[i++] = ch; // Append operands to postfix expression
    } else if (ch == '(') {
      stk->Push(ch); // Push '(' onto the stack
    } else if (ch == '+' || ch == '-' || ch == '*') {
      stk->Push(ch); // Push operators onto the stack
    } else if (ch == ')') {
      while (!stk->IsEmpty() && stk->Peek() != '(') {
        postFix[i++] = stk->Peek(); // Append operators to postfix expression
        stk->Pop();                 // Pop operators from the stack
      }
      stk->Pop(); // Pop '(' from the stack
    }
  }
  postFix[i] = '\0'; // Add null terminator at the end of the postfix expression
}

int Calc::Evaluate() {
  InFixToPostFix(); // Convert infix expression to postfix
  char ch;
  int op1, op2;
  for (int i = 0; postFix[i] != '\0';
       i++) { // Loop through the postfix expression
    ch = postFix[i];
    if (isalpha(ch)) {
      stk->Push(valueTbl[ch - 'A']); // Push operand value onto the stack

    } else if (isdigit(ch)) {
      stk->Push(ch - '0'); // Push digit onto the stack

    } else if (ch == '+' || ch == '-' || ch == '*') {
      op2 = stk->Pop();
      op1 = stk->Pop();

      switch (ch) {
      case '+':
        stk->Push(op1 + op2); // Perform addition and push result onto the stack
        break;
      case '-':
        stk->Push(op1 -
                  op2); // Perform subtraction and push result onto the stack
        break;
      case '*':
        stk->Push(op1 *
                  op2); // Perform multiplication and push result onto the stack
        break;
      }
    }
  }
  int result = stk->Pop(); // Pop final result from the stack
  return result;
}

void Calc::DisplayPostFix() { cout << "PostFix: " << postFix << endl; }

void Calc::DisplayInFix() { cout << "InFix: " << inFix << endl; }
