// Make array elements unique

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i=1;i<N;i++)
        {
            if(arr[i-1] < arr[i])
            {
                continue;
            }
            else
            {
                count = count + (arr[i-1] + 1 - arr[i]);
                arr[i] = arr[i-1] + 1;
            }
        }
        return count;
        return 0;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}