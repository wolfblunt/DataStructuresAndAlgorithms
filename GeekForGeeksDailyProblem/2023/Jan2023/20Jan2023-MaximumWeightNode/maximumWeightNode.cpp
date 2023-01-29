// Maximum Weight Node

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
        vector<int>weight(N,0);
        for(int i=0;i<N;i++)
        {
            if(Edge[i]!=-1)
            {
                weight[Edge[i]]+=i;
            }
        }
        int mx=INT_MIN;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(weight[i]>=mx)
            {
                 ans=i;
                 mx=weight[i];
            }
          
        }
        return ans;
  }
};

int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
