// Minimize the sum

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int sum=0;
        while(pq.size()>1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int temp = a+b;
            sum += temp;
            pq.push(temp);
        }
        return sum;
    }
};


int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}