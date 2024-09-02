#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int atoiMy(char* str[]);

/*
Description: Transforms a digit string stored as a c-string to an int. 
The function is invoked from main like this:
int num = atoiMy(argv[1]) or int num = atoiMy(argv[2])
argv[1] might look like this: ‘1’ ‘2’ ‘3’ ‘\0’   where each of the four characters
are stored in a character array.  After invoking atoiMy, num would contain the integer 123.  
Input: c-string containing  digits
Output: returns integer value of the digit string
*/
int atoiMy(char* str) {
    int result = 0; // Initialize result to 0.
    // Loop through each character in the string until the null terminator is reached.
    for (int i = 0; str[i] != '\0'; i++) {
        // Convert char to int and add it to result, accounting for place value by multiplying result by 10 each iteration.
        result = result * 10 + (str[i] - '0');
    }
    return result; // Return the final integer result.
}

int main(int argc, char* argv[]) {
    // Ensure the correct number of command line arguments are provided.
    if (argc != 4) {
        cerr << "Invalid input, Please try again. " << endl;
        return 1; // Return an error code.
    }
    // Open the output file.
    ofstream outFile(argv[3]);
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return 2; // Return an error code.
    }
    // Convert the digit strings to integers using atoiMy.
    int num1 = atoiMy(argv[1]);
    int num2 = atoiMy(argv[2]);
    // Multiply the numbers.
    int product = num1 * num2;
    // Write the product to the file.
    outFile << product;
    outFile.close(); // Close the file.
    cout << "Product written to " << argv[3] << endl;
    return 0; // Successful execution.
}

//https://docs.google.com/document/d/1cQLfiy4hvlhRLqqwNgv6rwh9-6354bZL-kG8902EpeM/edit#heading=h.6fxiynwr0aa5

//argv[0] is ./a.out 'usage'
//argv[1] is digit string 1 
//argv[2] is digit string 2
//argv[3] is output file name

//argc is the number of arguments passed to the program

// g++ project2.cpp -o project2
// ./project2 123 456 result.txt