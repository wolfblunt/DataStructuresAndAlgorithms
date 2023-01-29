// Find minimum number of Laptops required

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(start[i], end[i]));
        }
        sort(v.begin(), v.end());
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(pq.size()==0)
            {
                pq.push(v[i].second);
                count++;
            }
            else if(pq.top() <= v[i].first)
            {
                pq.push(v[i].second);
                pq.pop();
            }
            else
            {
                count++;
                pq.push(v[i].second);
            }
        }
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}