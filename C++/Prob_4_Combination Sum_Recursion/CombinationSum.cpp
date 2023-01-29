//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public: vector<vector<int>> ans;
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> v;
        sort(A.begin(), A.end());
        set<int> s(A.begin(), A.end());
        A.assign(s.begin(), s.end());
        sum_combination(A, B, v, 0);
        return ans;
    }
    
    void sum_combination(vector<int> &A, int B, vector<int> &val, int i)
    {
        if(B==0)
        {
            ans.push_back(val);
        }
        if(i==A.size())
        {
            return;
        }
        while(B-A[i]>=0 && i<A.size())
        {
            val.push_back(A[i]);
            sum_combination(A,B-A[i],val,i);
            i++;
            val.pop_back();
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends