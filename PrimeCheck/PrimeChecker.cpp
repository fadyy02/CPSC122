/*
 Name: Fady Youssef
 Class: CPSC 122, Section 1
 Date Submitted: January 18, 2024
 Assignment: Project 1
 Description: This program computes prime numbers.
 Sources:
          https://www.rookieslab.com/posts/fastest-way-to-check-if-a-number-is-prime-or-not#c-
 implementation-of-sieve-of-eratosthenes (Sieve of Eratosthenes)

 https://stackoverflow.com/questions/62150130/algorithm-of-checking-if-the-number-is-prime

 https://stackoverflow.com/questions/453793/which-is-the-fastest-algorithm-to-find-prime-numbers

 https://www.geeksforgeeks.org/prime-numbers/

 https://www.geeksforgeeks.org/sieve-of-eratosthenes/

*/

#include <cmath>
#include <iostream>

using namespace std;

// Function to check if a number is prime
bool isPrime(int number) {
  // if sqrt returns whole number that can be divided by itself, then its not a
  // prime
  for (int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}

// generates primes and displayes them
int display(int inputPrime, int inputRow) {
  int ct = 0, rowCt = 0, sequenceNum = 2;

  if (inputPrime <= 0 || inputRow <= 0) {
    cout << "Error: Arguments must be positive integers. Please try again.\n";
    return 0;
  }
  // as long as the number of primes is less than the total primes, continue
  // printing
  while (ct < inputPrime) {
    if (isPrime(sequenceNum)) {
      // adds tab between each num
      cout << sequenceNum << '\t';
      ct++;
      rowCt++;
      // if the number of primes in a row is equal to the input row, start a new
      // line
      if (rowCt == inputRow) {
        cout << endl;
        rowCt = 0;
        // used ai in the last 3 lines, figure this out
      }
    }
    sequenceNum++;
  }
  return 0;
}

// Runna
int main(int argc, char *argv[]) {
  int nums = atoi(argv[1]);
  int cols = atoi(argv[2]);
  display(nums, cols);
  return 0;
}

// g++ PrimeChecker.cpp -o PrimeChecker
// ./PrimeChecker 10 5

// Miller rabin test (faster algo)
// Sieve of Eratosthenes:
// Trial Division:

// easy algo: check if greater than one, if division by 2,3,or itself =0
// false, else is true

// in main for display function passes num initialized as inputPrime and col
// initialized as inputRow

// time complexity: O(sqrt(n))
// space complexity: O(1)
