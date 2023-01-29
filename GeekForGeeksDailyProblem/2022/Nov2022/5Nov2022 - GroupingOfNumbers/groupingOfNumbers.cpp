#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        unordered_map<int, int> um;
        for(int i=0;i<N;i++)
        {
            um[arr[i]%K]++;
        }
        
        int size = 0;
        int left = 1;
        int right = K-1;
        
        while(left<right)
        {
            if(um[left] >= um[right])
            {
                size+=um[left];
            }
            if(um[left] < um[right])
            {
                size+=um[right];
            }
            left++;
            right--;
        }
        
        if(left == right && um[left] > 0)
        {
            size++;
        }
        
        if(um[0]>0)
        {
            size++;
        }
        
        return size;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}