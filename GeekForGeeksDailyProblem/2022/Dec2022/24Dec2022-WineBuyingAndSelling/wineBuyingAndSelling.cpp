// Wine Buying and Selling

#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      vector<pair<int,int>> positive;
      vector<pair<int,int>> negative;
      for(int i=0;i<N;i++)
      {
          if(arr[i]>0)
          {
              positive.push_back(make_pair(arr[i],i));
          }
          else
          {
              negative.push_back(make_pair(arr[i],i));
          }
      }
      
      long long int result = 0;
      int i=0; j=0;
      while(i<positive.size() && j<negative.size())
      {
          long long int temp = min(positive[i].first)
      }
  }
};




int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}