#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool primeNumberCheck(int p)
    {
        bool notPrime = true;
        for(int i=2;i<=p/2;i++)
        {
            if(p%i==0)
            {
                notPrime = false;
                break;
            }
        }
        return notPrime;
    }

    string isSumOfTwo(int N){
        if(N%2==1 && primeNumberCheck(N-2)){

            return "Yes";
        }
        else if(N%2){

            return "No";
        }
        for(int i=2;i<=N/2;i++)
        {
            if(primeNumberCheck(i) && primeNumberCheck(N-i))
            {
                return "Yes";
            }
        }
        return "No";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}