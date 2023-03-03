/* Cutting Rectangles

Approach:
This problem has been solved using GCD (Greatest Common Divisor) approach because gcd is the largest number that can divide both number hence giving us largest dimension of the square . 

The time complexity of the above solution is O(log(min(L,B))), where L and B are the dimensions of the rectangle.

This is because the time complexity of the findGCD helper function is O(log(min(a,b))), where a and b are the inputs to the function. The rest of the operations in the minimumSquares function take constant time, so they do not affect the overall time complexity. Therefore, the overall time complexity of the solution is O(log(min(L,B))). 

*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    long long int findGCD(long long int a, long long int b)
    {
        if(b==0)
        {
            return a;
        }
        return findGCD(b, a%b);
    }
    
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        vector<long long int> ans;
        long long int gcdd = findGCD(L, B);
        long long int noOfSquares = (L*B)/(gcdd*gcdd);
        ans.push_back(noOfSquares);
        ans.push_back(gcdd);
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}