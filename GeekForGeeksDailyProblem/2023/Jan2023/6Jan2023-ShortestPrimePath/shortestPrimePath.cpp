// Shortest Prime Path

#include<bits/stdc++.h>
using namespace std;

class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        if(Num1 == Num2)
        {
            return 0;
        }
        vector<int> primeNumber(10000,1);
        for(int i=2;i<=sqrt(9999);i++)
        {
            if(primeNumber[i])
            {
                for(int j=i*i;j<=9999;j+=i)
                {
                    primeNumber[j]=0;
                }
            }
        }
        
        // Using BFS
        unordered_set<string> s;
        queue<pair<string, int>> q;
        string start = to_string(Num1);
        string end = to_string(Num2);
        
        q.push(make_pair(start, 0));
        
        s.insert(start);
        
        while(!q.empty())
        {
            string num = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(num==end)
                return steps;
                
            for(int i=0;i<4;i++)
            {
                char c = num[i];
                for(char ch='0'; ch<='9';ch++)
                {
                    if(ch=='0' && i==0)
                        continue;
                    
                    num[i] = ch;
                    int val = stoi(num);
                    if(primeNumber[val])
                    {
                        if(s.find(num) == s.end())
                        {
                            s.insert(num);
                            q.push(make_pair(num, steps+1));
                        }
                    }
                    
                }
                num[i] = c;
            }
        }
        return -1;
    }
};


signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}