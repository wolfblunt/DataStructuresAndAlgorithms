// Minimum X (xor) A

class Solution {
public:
    int countSetBits(int a)
    {
        int noOfbits = 1;
        while(a & (a-1))
        {
            noOfbits++;
            a = a & (a-1);
        }
        return noOfbits;
    }

    int minimizeXor(int a, int b) {
        int noOfSetBitInb = countSetBits(b);
        int noOfSetBitInx = noOfSetBitInb;
        int ans = 0;
        for(int i=31;i>=0 && noOfSetBitInx;i--) 
        {
            if(a & (1<<i))
            {
                ans |= (1<<i);
                noOfSetBitInx--;
            }
        }
        
        for(int i=0;i<=31 && noOfSetBitInx;i++) 
        {
            if((ans & (1<<i)) == 0)
            {
                ans |= (1<<i);
                noOfSetBitInx--;
            }
        }
        return ans;
    }
};