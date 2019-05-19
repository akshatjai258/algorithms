// Day 01: Data Types.

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int input_i;
    double input_d;
    string input_s;

    getline(cin, input_s);
    input_i = stoi(input_s);
    getline(cin, input_s);
    input_d = stod(input_s);
    getline(cin, input_s);

    cout << i + input_i << "\n";
    printf("%.1f", d + input_d);
    cout << "\n" << s + input_s << "\n";
    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.


    return 0;
}