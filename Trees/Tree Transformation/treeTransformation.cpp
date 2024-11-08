// Tree Transformation

#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
    int solve(int n, vector<int> p){
       int i,ans=n-1;
        vector<int>degree(n+1,0);
        for(i=1;i<n;i++){
            degree[p[i]]++;
            degree[i]++;
        }
        for(i=0;i<n;i++)if(degree[i]==1)ans--;
        
        if(ans<0)return 0;
        return ans;
        
    }
};



int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   