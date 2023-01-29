using namespace std;
#include <iostream>
int main()
{
    cout<<"Hello Aman";
    int x; 
    cout << "Type a number: "; // Type a number and press enter
    cin >> x; // Get user input from the keyboard
    cout << "Your number is: " << x; // Display the input value
    // int x;
    // cin >> x;
    for(int i=0;i<x;i++)
    {
        cout << i;
    }
    return 0;
}