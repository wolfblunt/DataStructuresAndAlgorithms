class Solution {
  public:
    int sumOfDigit(int N)
    {
        int sum=0;
        while(N>0)
        {
            sum+=(N%10);
            N = N/10;
        }
        return sum;
    }
  
    string BalancedString(int N) {
        string alphabets="abcdefghijklmnopqrstuvwxyz";
        string result = "";
        int iterations = N/26;
        int remaining = N%26;
        for(int i=0;i<iterations;i++)
        {
            result+=alphabets;
        }
        
        int front;
        int last;
        if(remaining%2==1)
        {
            front = last = remaining/2;
            if(sumOfDigit(N)%2==0)
            {
                front+=1;
            }
            else
            {
                last+=1;
            }
        }
        else
        {
            front = last = remaining/2;
        }
        
        result += alphabets.substr(0, front) + alphabets.substr(26-last, last);
        return result;
    }
};