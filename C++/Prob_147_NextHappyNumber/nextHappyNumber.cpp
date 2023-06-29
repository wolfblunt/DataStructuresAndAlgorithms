// Next Happy Number

#include<bits/stdc++.h> 
using namespace std;

class Solution{
public:
    /*
        Points to Remember:
        - from number 1,2,...,9 only 1 and 7 are happy number
        - So when the sum of any number will be converted into single digit then we will check if the sum is 1 or 7 
        then the number is happy number otherwise not a happy number.
    */
    bool isNoHappy(int num)
    {
        if(num==1 || num==7)
        {
            return true;
        }
        int sum = num;
        int temp = sum;
        while(sum > 9)
        {
            sum = 0;
            while(temp>0)
            {
                int r = temp%10;
                sum += r*r;
                temp = temp/10;
            }
            if(sum == 1)
            {
                return true;
            }
            temp = sum;
        }
        
        if(sum == 7)
        {
            return true;
        }
        return false;
    }
    
    int nextHappy(int N){
        int num = N+1;
        while(true)
        {
            if(isNoHappy(num))
            {
                return num;
            }
            num++;
        }
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}