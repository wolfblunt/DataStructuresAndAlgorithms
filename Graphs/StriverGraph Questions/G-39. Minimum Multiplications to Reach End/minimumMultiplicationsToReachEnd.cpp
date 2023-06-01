// Minimum Multiplications to reach End

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min heap - {step, multiplied no}
        vector<int> num(100000, 1e9);
        
        num[start] = 0;
        pq.push(make_pair(0, start));
        int mod = 100000;
        while(!pq.empty())
        {
            auto element = pq.top();
            pq.pop();
            int step = element.first;
            int node = element.second;
            
            if(node == end)
            {
                return step;
            }
            
            for(int i=0;i<arr.size();i++)
            {
                int new_node = (node*arr[i]) % mod;
                if(step+1 < num[new_node])
                {
                    num[new_node] = step + 1;
                    pq.push(make_pair(step+1, new_node));
                }
            }
        }
        
        return -1;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}