// Last modified ball

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int solve(int N, vector<int> A) {
        int n = A.size();
        int count;
        for(int i=0;i<n;i++)
        {
            if(A[i] < 9)
                count = i+1;
        }
        return count;
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}