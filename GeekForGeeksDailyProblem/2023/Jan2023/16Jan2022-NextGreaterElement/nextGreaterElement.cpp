// Next Greater Element

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        reverse(arr.begin(), arr.end());
        stack<long long> s;
        vector<long long> ans;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[i]>s.top())
            {
                s.pop();
            }
            if(s.empty())
            {
                s.push(arr[i]);
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
                s.push(arr[i]);
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}