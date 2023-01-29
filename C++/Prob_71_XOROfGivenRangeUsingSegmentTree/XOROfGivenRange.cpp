#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void buildSegmentTree(int index,int low,int high, vector<int>&nums, vector<int>& segmentTree)
    {
        if(low==high)
        {
            segmentTree[index] = nums[low];
            return;
        }
        
        int mid = (low+high)/2;
        buildSegmentTree(2*index+1, low, mid, nums, segmentTree);
        buildSegmentTree(2*index+2, mid+1, high, nums, segmentTree);
        segmentTree[index] = segmentTree[2*index+1] ^ segmentTree[2*index+2];
    }
    
    int segmentXORQuery(int index,int low, int high, int lrange, int hrange, vector<int>& segmentTree)
    {
        if(lrange>high || hrange<low)
        {
            return 0;
        }
        
        if(lrange<=low && hrange>=high)
        {
            return segmentTree[index];
        }
        int mid = (low+high)/2;
        int p = segmentXORQuery(2*index+1, low, mid, lrange, hrange, segmentTree);
        int q = segmentXORQuery(2*index+2, mid+1, high, lrange, hrange, segmentTree);
        return p^q;
    }
    
    int getXor(vector<int>&nums, int a, int b){
        int n = nums.size();
        vector<int> segmentTree;
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1, nums, segmentTree);
        return segmentXORQuery(0, 0, n-1, a,b, segmentTree);
    }
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}