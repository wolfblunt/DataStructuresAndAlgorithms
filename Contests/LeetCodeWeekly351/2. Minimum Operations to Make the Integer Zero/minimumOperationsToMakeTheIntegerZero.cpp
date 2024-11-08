// Minimum Operations to Make the Integer Zero

class Solution {
public:
    int countSetBits(long long num)
    {
        int count = 0;
        while(num > 0)
        {
            count += num & 1;
            num = num >> 1;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2)
    {
        if(num1 <= num2)
            return -1;

        for(int steps=0;steps<=40;steps++)
        {
            long long diff = num1 - (num2) * 1LL*steps;
            int bits = countSetBits(diff);
            if(bits <= steps && steps <= diff)
            {
                return steps;
            }
        }

        return -1;
    }
};