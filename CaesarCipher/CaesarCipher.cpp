/*
Team Member 1: Paul De Palma
Course: CPSC 122
Date Submitted: 2/10/2024
Assignment Name: Project 3
Description Program implements the Caesar Cipher
*/

#include <iostream>
#include <fstream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cctype>  // For isalpha() and toupper()
using namespace std;
//Note that variable names in the next three statements for documentation purposes only
void keyGen(string keyFile);
char encrypt(char ch, int key);
char decrypt(char ch, int key);
void control(int mode, string keyFile, string input, string output);


int main(int argc, char* argv[])
{
 int mode;
 string keyFile, input, output;

 if (argc != 3 && argc != 5) 
 {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
 }

 mode = atoi(argv[1]);
 keyFile = argv[2];

 if (argc == 3)
  {
   keyGen(keyFile);
   return 0; 
  }

 if (argc == 5)
  {
   input = argv[3];
   output = argv[4];
   control(mode, keyFile, input, output); 
  }

 return 0;
}

/*
Description: Generates and stores an integer key in the range [1..25]
Input: Name of output file
Output: none. Generated key is stored in the output file 
*/
void keyGen(string keyFile)
{
    srand(time(0)); // Seed the random number generator
    int key = rand() % 25 + 1; // Generate a random key between 1 and 25
    ofstream outFile(keyFile);
    if (outFile.is_open())
    {
        outFile << key;
        outFile.close();
    }
    else
    {
        cout << "Unable to open file: " << keyFile << endl;
    }
}

/*
Description; 
1 Opens keyfile and reads key 
2 Opens plaintext and ciphertext files 
3 Reads each character of the plaintext file 
4 If mode is 1 and the character is alphabetic, transforms it to upper case, encrypts it and writes it
  to the output file 
5 If mode is 2 and the character is alphabetic, decrypts it and writes it to output file
6 If the character is not alphabetic, writes it to the output file
7 Closes all three files
Input: Encrypt/decrypt mode, namkes of key file, input, and output files
Output: Writes encrypted/decrypted text to output file
*/
void control(int mode, string keyFile, string input, string output)
{
    int key;
    ifstream keyIn(keyFile);
    if (keyIn.is_open())
    {
        keyIn >> key;
        keyIn.close();
    }
    else
    {
        cout << "Unable to open key file: " << keyFile << endl;
        return;
    }

    ifstream inFile(input);
    ofstream outFile(output);
    if (!inFile.is_open() || !outFile.is_open())
    {
        cout << "Unable to open input/output files." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        if (mode == 1) // Encrypt
        {
            ch = encrypt(ch, key);
        }
        else if (mode == 2) // Decrypt
        {
            ch = decrypt(ch, key);
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();
}

// Function to decrypt Caesar cipher with a given shift
string decryptCaesar(const string& ciphertext, int shift) {
    string plaintext;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plaintext += 'A' + (c - base - shift + 26) % 26;
        } else {
            plaintext += c; // Non-alphabetic characters remain unchanged
        }
    }
    return plaintext;
}

// Function to perform brute force attack to decrypt Caesar cipher
void bruteForceCaesar(const string& ciphertext) {
    cout << "Brute Force Attack Results:" << endl;
    for (int shift = 0; shift < 26; ++shift) {
       string decrypted = decryptCaesar(ciphertext, shift);
        cout << "Shift " << shift << ": " << decrypted << endl;
    }
}

/*
Description: Encrypts a single character with key according to the rules for substitution cipher
             encryption
Input: character to be encrypted with key
Output: returns encrypted character 
*/
char encrypt(char ch, int key)
{
    if (isalpha(ch))
    {
        ch = toupper(ch); // Convert to uppercase
        ch = (ch - 'A' + key) % 26 + 'A'; // Encrypt character
    }
    return ch;
}

/*
Description: Decrypts a single character with key according to the rules for substitution cipher
             encryption
Input: character to be decrypted with key
Output: returns decrypted character 
*/
// Updated decrypt function
char decrypt(char ch, int key)
{
    if (isalpha(ch))
    {
        ch = toupper(ch); // Convert to uppercase
        ch = (ch - 'A' - key + 26) % 26 + 'A'; // Decrypt character
    }
    return ch;
}


// g++ project3.cpp 
// ./a.out 0 keyFile
// ./a.out 1 keyFile.txt input.txt output.txt // encrypt
// ./a.out 2 keyFile.txt input.txt output.txt // decrypt