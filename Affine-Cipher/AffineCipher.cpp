/*
Team Member 1: Fady Youssef
Course: CPSC 122
Date Submitted: 2/20/2024
Assignment Name: Project 5
Description Program implements the Affine Cipher
*/

#include <cctype>  // For isalpha() and toupper()
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Note that variable names in the next three statements freor documentation
// purposes only
void keyGen(string keyFile);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
void control(int mode, string keyFile, string input, string output);

int main(int argc, char *argv[]) {
  int mode;
  string keyFile, input, output;

  if (argc != 3 && argc != 5) {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
  }

  mode = atoi(argv[1]);
  keyFile = argv[2];

  if (argc == 3) {
    keyGen(keyFile);
    return 0;
  }

  if (argc == 5) {
    input = argv[3];
    output = argv[4];
    control(mode, keyFile, input, output);
  }

  // Add your custom modifications here
  if (mode != 1 && mode != 2) {
    cout << "Invalid mode. Mode should be 1 for encrypt, 2 for decrypt."
         << endl;
    return 1;
  }

  return 0;
} // main is exact same as in proj3

/*
Description: Generates and stores an integer key in the range [1..25]
Input: Name of output file
Output: none. Generated key is stored in the output file
*/
void keyGen(string keyFile) {
  ofstream outFile(keyFile);
  int key = 1 + rand() % 25; // Generate random key between 1 and 25
  if (outFile.is_open()) {
    outFile << key;
    outFile.close();
  } else {
    cout << "Unable to open file: " << keyFile << endl;
  }
}

/*
Description;
1 Opens keyfile and reads key
2 Opens plaintext and ciphertext files
3 Reads each character of the plaintext file
4 If mode is 1 and the character is alphabetic, transforms it to upper case,
encrypts it and writes it to the output file 5 If mode is 2 and the character is
alphabetic, decrypts it and writes it to output file 6 If the character is not
alphabetic, writes it to the output file 7 Closes all three files Input:
Encrypt/decrypt mode, namkes of key file, input, and output files Output: Writes
encrypted/decrypted text to output file
*/
void control(int mode, string keyFile, string input, string output) {

  // this is the array of multiplicative indices mod 26
  int alpha, beta, MI[26] = {0, 1, 0, 9, 0,  21, 0,  15, 0, 0, 0,  19, 0,
                             0, 0, 7, 0, 23, 0,  11, 0,  5, 0, 17, 0};

  ifstream keyIn(keyFile);
  ifstream inFile(input);
  ofstream outFile(output);

  if (keyIn.is_open() && inFile.is_open() && outFile.is_open()) {
    keyIn >> alpha; // Read alpha from key file
    keyIn.close();

    if (mode == 1) // Encrypt mode
    {
      while (!inFile.eof()) {
        char ch;
        inFile.get(ch); // Read character from input file
        if (isalpha(ch)) {
          ch = encrypt(ch, alpha, beta);
        }
        outFile << ch; // Write character to output file
      }

    } else if (mode == 2) // Decrypt mode
    {
      while (!inFile.eof()) {
        char ch;
        inFile.get(ch); // Read character from input file
        if (isalpha(ch)) {
          ch = decrypt(ch, alpha, beta, MI);
        }
        outFile << ch; // Write character to output file
      }

    } else {
      cout << "Invalid mode. Mode should be 1 for encrypt, 2 for decrypt."
           << endl;
    }

    // Close all open files
    inFile.close();
    outFile.close();

  } else {
    cout
        << "Unable to open file(s). Check if all files exist and are accessible"
        << endl;
  }
}

/*
Description: Encrypts a single character with key according to the rules for
affine cipher encryption Input: character to be encrypted with key Output:
returns encrypted character
*/
char encrypt(char ch, int alpha, int beta) {
  int pos = ch - 'A';

  if (isalpha(ch)) {
    ch = toupper(ch);                         // Convert to uppercase
    ch = ((alpha * (pos) + beta) % 26) + 'A'; // Encrypt character
  }
  return ch;
}

/*
Description: Decrypts a single character with key according to the rules for
affine cipher decryption Input: character to be decrypted with key Output:
returns decrypted character
*/
char decrypt(char ch, int alpha, int beta, int MI[]) {
  int pos = ch - 'A';

  if (isalpha(ch)) {
    ch = toupper(ch);                                // Convert to uppercase
    ch = (MI[pos] * ((26 - alpha) % 26) % 26) + 'A'; // Decrypt character
  }
  return ch;
}

// https://www.tutorialspoint.com/cplusplus-program-to-implement-affine-cipher

// g++ project5.cpp
// ./a.out 1 keyFile.txt input.txt output.txt

// test checkk