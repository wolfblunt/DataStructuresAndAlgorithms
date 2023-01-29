// Carpet into Box

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int count=0;
        int cl = max(A,B);
        int cb = min(A,B);
        int l = max(C,D);
        int b = min(C,D);
        
        while(cl>l || cb>b)
        {
            if(cl>l && cb>b)
            {
                cl = cl/2;
            }
            else if(cl>l)
            {
                cl = cl/2;
            }
            else
            {
                cb = cb/2;
            }
            A = cl;
            B = cb;
            cl = max(A,B);
            cb = min(A,B);
            count++;
        }
        return count;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}