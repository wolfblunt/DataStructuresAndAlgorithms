// Min operations

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int a, int b) {
        if(a==b)
            return 0;
        
        if((a & b) == a || (a & b) == b)
            return 1;
        
        return 2;
    }
};


int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}