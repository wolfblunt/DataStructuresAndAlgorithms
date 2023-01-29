#include <bits/stdc++.h>
using namespace std;
 
void printTwinPrime(int n)
{
    // Create a boolean array "prime[0..n]"
    // and initialize all entries it as true.
    // A value in prime[i] will finally be false
    // if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
         
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true) {
             
            // Update all multiples of p
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // to check for twin prime numbers
    // display the twin primes
    for (int p = 2; p <= n - 2; p++)
        if (prime[p] && prime[p + 2])
            cout << "(" << p << ", " << p + 2 << ")" ;
}
 
// Driver Program to test above function
int main()
{
    int n = 20;
     
    // Calling the function
    printTwinPrime(n);
 
    return 0;
}