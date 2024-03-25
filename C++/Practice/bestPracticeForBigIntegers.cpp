#include <bits/stdc++.h>
using namespace std;
 
// Main driver method with int32_t return type
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // using sizeof() method
    cout << "size of int = " << sizeof(int) << '\n';
 
// Defining int as long long int
#define int long long int
 
    // Calculating new size of Integer data type
    // again using standard sizeof() method
    cout << "new size of int = " << sizeof(int) << '\n';
 
    // Big custom input integer
    int x = 1e18;
 
    // Print and display this big integer value
    cout << "value of x = " << x << endl;
 
    return 0;
}