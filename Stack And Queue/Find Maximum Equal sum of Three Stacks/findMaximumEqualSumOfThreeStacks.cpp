// Find Maximum Equal sum of Three Stacks

#include <bits/stdc++.h>
using namespace std;




class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        for(auto a: S1)
        {
            sum1 += a;
        }
        
        for(auto a: S2)
        {
            sum2 += a;
        }
        
        for(auto a: S3)
        {
            sum3 += a;
        }
        
        int i=0, j=0, k=0;
        while(i<N1 && j<N2 && k<N3)
        {
            if(sum1 == sum2 && sum2 == sum3)
            {
                return sum1;
            }
            
            else if(sum1>=sum2 && sum1>=sum3)
            {
                sum1 -= S1[i++];
            }
            
            else if(sum2>=sum1 && sum2>=sum3)
            {
                sum2 -= S2[j++];
            }
            
            else if(sum3>=sum1 && sum3>=sum2)
            {
                sum3 -= S3[k++];
            }
        }
        
        return 0;
    }
};



int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}