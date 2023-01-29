#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long jumpingNums(long long X) {
        if(X<=10)
        {
            return X;
        }
        
        queue<long long> q;  // generating all jumping number till X and store in queue
        
        for(int i=0;i<=9;i++)
        {
            q.push(i);
        }
        
        long long answer=0;
        
        while(!q.empty())
        {
            long long currentNo = q.front();
            q.pop();
            
            if(currentNo>X)
            {
                continue;
            }
            
            answer = max(answer, currentNo);
            int n = (int)currentNo%10;
            
            if(n)  // If n is not 0
            {
                long long temp = currentNo*10+(n-1);
                q.push(temp);
            }
            if(n!=9) // If n is not 9
            {
                long long temp = currentNo*10+(n+1);
                q.push(temp);
            }
        }
        
        return answer;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
