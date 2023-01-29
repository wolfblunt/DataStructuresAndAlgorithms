// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     cout<<"Hello Aman\n";
//     int x; 
//     cout << "Type a number: "; 
//     cin >> x;
//     cout << "Your number is: " << x << "\n"; 
//     string fname = "Aman";
//     string lname;
//     cout << "Enter your last name\n";
//     cin >> lname;
//     cout << "Full Name : "+fname+" "+lname+"\n";
//     for(int i=0;i<x;i++)
//     {
//         cout << i;
//         cout <<"\n";
//     }
//     int arr[5] = {11,12,13,14,15};
//     cout << "printing array";
//     for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
//     {
//         cout << arr[i]<<" ,";
//     }
//     return 0;
// }

#include<iostream>
#include<string.h>
using namespace std;

void Palindrome(char arr[])
{
    int l=0;
    int h=strlen(arr)-1;
    while(h>l)
    {
        if (arr[h--] != arr[l++])
        {
            cout<<"Not a palindrome\n";
            return;
        }
    }
    cout<<"String is Palindrome\n";
}

int main()
{
    string s;
    char c = 'o';
    cout<<"Enter the String";   // Hello World
    getline(cin, s);
    int n = s.length();
    printf("Size of string : %d\n",n);
    int start_index = -1;
    int end_index = -1;
    for(int i=0;i<n;i++)
    {
        cout<<"Char i : "<<s[i];
        if(s[i]==c)
        {
            cout<<"Inside If";
            if(start_index==-1)
            {
                start_index = i;
            }
            end_index = i;
        }
    }
    cout<<"START INDEX : "<<start_index<<" & END INDEX : "<<end_index;
    return 0;
}