// Ticket Counter

#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int> q;
        int val = K;
        
        for(int i=1;i<=N;i++)
        {
            q.push_back(i);
        }
        
        int flag = 0;
        while(!q.empty())
        {
            if(val==0)
            {
                val = K;
                if(flag == 0)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
            
            if(flag == 0)
            {
                while(!q.empty() && val > 0)
                {
                    if(q.size() == 1)
                    {
                        return q.front();
                    }
                    q.pop_front();
                    val--;
                }
            }
            
            if(flag == 1)
            {
                while(!q.empty() && val > 0)
                {
                    if(q.size() == 1)
                    {
                        return q.front();
                    }
                    q.pop_back();
                    val--;
                }
            }
        }
        
        return -1;
    }
};



int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}