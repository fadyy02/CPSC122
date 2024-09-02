/*
Team Member 1: Fady Youssef
Course: CPSC 122
Date Submitted: 2/10/2024
Assignment Name: Project 4
Description: Program reads an unsorted file of strings, sorts it alphabetically
by letters, and writes it out. Extra characters that aren't letters are pushed
to the end of each line.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void selectionSortByLetter(string *arr, int numLines);
void swap(char &a, char &b);
void pushNonLetterToEnd(string &line);

void control(string input, string output, int numLines);
int countLines(string input);

int main(int argc, char *argv[]) {
  // Check if the number of command line arguments is correct
  if (argc != 3) {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
  }

  string input = argv[1];  // Input file
  string output = argv[2]; // Output file

  int numLines = countLines(input);
  control(input, output, numLines);

  return 0;
}

int countLines(string input) {
  // Open the file and count the number of lines in it
  ifstream file(input);
  int numLines = 0;
  string line;
  while (getline(file, line)) {
    numLines++;
  }
  return numLines;
}

void control(string input, string output, int numLines) {
  // Open input and output files, read lines into an array, sort the lines
  // alphabetically by characters, and write them to the output file
  ifstream inputFile(input);
  ofstream outputFile(output);
  string *lines = new string[numLines];
  string line;
  int lineCounter = 0;
  for (int i = 0; i < numLines; i++) {
    getline(inputFile, line);
    pushNonLetterToEnd(line); // Push extra non-letter characters to the end
    lines[i] = line;
    lineCounter++;
  }

  selectionSortByLetter(lines, numLines);

  for (int i = 0; i < numLines; i++) {
    outputFile << lines[i] << endl;
  }

  cout << "Sorted lines written to " << output << endl;

  inputFile.close();
  outputFile.close();
  delete[] lines;
}

void selectionSortByLetter(string *arr, int numLines) {
  // Sort each line alphabetically by characters using selection sort algorithm
  for (int k = 0; k < numLines; k++) {
    string line = arr[k];
    int n = line.length();
    for (int i = 0; i < n; i++) {
      int min_idx = i;
      for (int j = i + 1; j < n; j++) {
        if (line[j] < line[min_idx]) {
          min_idx = j;
        }
      }
      swap(line[i], line[min_idx]);
    }
    arr[k] = line;
  }
}

void swap(char &a, char &b) {
  // Function to swap two characters
  char temp = a;
  a = b;
  b = temp;
}

void pushNonLetterToEnd(string &line) {
  // Move extra characters that are not letters to the end of the line
  int pos = 0;
  for (char c : line) {
    if (!isalpha(c)) {
      line.erase(pos, 1);
      line += c;
    } else {
      pos++;
    }
  }
}

// https://www.geeksforgeeks.org/program-to-sort-an-array-of-strings-using-selection-sort/
// ifsream fin;
// fin.open(input);

// g++ StringSorter.cpp -o StringSorter
// ./StringSorter input.txt output.txt