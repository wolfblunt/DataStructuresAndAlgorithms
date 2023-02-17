// Is it Fibonacci

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        if(K>=N)
        {
            return GeekNum[N-1];
        }
        vector<long long> fibonacciArray = GeekNum;
        long long sum = 0;
        for(auto a: fibonacciArray)
        {
            sum+=a;
        }
        fibonacciArray.push_back(sum);
        for(long long i=K+1;i<=N;i++)
        {
            sum+=fibonacciArray[i-1];
            sum-=fibonacciArray[i-K-1];
            fibonacciArray.push_back(sum);
        }
        return fibonacciArray[N-1];
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}