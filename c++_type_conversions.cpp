// C++ Type Conversions

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Initial values
    int i = 65;
    char c = 'A';
    string s = "123";
    float f = 3.14f;
    double d = 5.678;

    // INT to other types
    int intVal = 65;
    char intToChar = (char)intVal;            // Casting to char (ASCII)
    string intToString = to_string(intVal);   // Using to_string()
    float intToFloat = (float)intVal;         // Casting to float
    double intToDouble = (double)intVal;      // Casting to double

    // CHAR to other types
    char charVal = 'A';
    int charToInt = (int)charVal;             // Casting to int (ASCII value)
    string charToString(1, charVal);          // Constructor with count and char
    float charToFloat = (float)charVal;       // Casting to float (ASCII value)
    double charToDouble = (double)charVal;    // Casting to double (ASCII value)

    // STRING to other types
    string strVal = "123";
    int stringToInt = stoi(strVal);           // String to int
    float stringToFloat = stof(strVal);       // String to float
    double stringToDouble = stod(strVal);     // String to double
    char stringToChar = strVal[0];            // First character of string

    // FLOAT to other types
    float floatVal = 3.14f;
    int floatToInt = (int)floatVal;           // Casting to int (truncates)
    string floatToString = to_string(floatVal); // Using to_string()
    double floatToDouble = (double)floatVal;  // Casting to double
    char floatToChar = (char)floatVal;        // Casting to char (ASCII)

    // DOUBLE to other types
    double doubleVal = 5.678;
    int doubleToInt = (int)doubleVal;         // Casting to int (truncates)
    string doubleToString = to_string(doubleVal); // Using to_string()
    float doubleToFloat = (float)doubleVal;   // Casting to float
    char doubleToChar = (char)doubleVal;      // Casting to char (ASCII)

    // Printing examples
    cout << "int to char: " << intToChar << endl;        // Outputs: A
    cout << "int to string: " << intToString << endl;    // Outputs: 65
    cout << "int to float: " << intToFloat << endl;      // Outputs: 65.000000
    cout << "int to double: " << intToDouble << endl;    // Outputs: 65.000000

    cout << "char to int: " << charToInt << endl;        // Outputs: 65
    cout << "string to int: " << stringToInt << endl;    // Outputs: 123
    cout << "float to int: " << floatToInt << endl;      // Outputs: 3
    cout << "double to int: " << doubleToInt << endl;    // Outputs: 5

    return 0;
}