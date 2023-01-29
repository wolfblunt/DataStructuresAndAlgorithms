#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            if(k==0)
            {
                return n*m;
            }
            
            vector<int> columnVec;
            vector<int> rowVec;
            
            for(int i=0;i<enemy.size();i++)
            {
                rowVec.push_back(enemy[i][0]);
                columnVec.push_back(enemy[i][1]);
            }
            
            sort(columnVec.begin(), columnVec.end());
            sort(rowVec.begin(), rowVec.end());
            
            int columnLength = columnVec[0] - 1;
            
            for(int i=0;i<columnVec.size();i++)
            {
                if(i==columnVec.size()-1)
                {
                    columnLength = max(columnLength, m-columnVec[i]);
                }
                else
                {
                    columnLength = max(columnLength, columnVec[i+1]-columnVec[i]-1);
                }
            }
            
            int rowLength = rowVec[0] - 1;
            
            for(int i=0;i<rowVec.size();i++)
            {
                if(i==rowVec.size()-1)
                {
                    rowLength = max(rowLength, n-rowVec[i]);
                }
                else
                {
                    rowLength = max(rowLength, rowVec[i+1]-rowVec[i]-1);
                }
            }
            
            return rowLength*columnLength;
        }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
