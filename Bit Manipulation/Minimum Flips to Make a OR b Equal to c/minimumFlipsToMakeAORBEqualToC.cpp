// Minimum Flips to Make a OR b Equal to c

class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        int bit_a, bit_b, bit_c;
        int count = 0;
        while(a || b || c)
        {
            bit_a = a & 1;
            bit_b = b & 1;
            bit_c = c & 1;

            if((bit_a | bit_b) != bit_c)
            {
                if(bit_a == 1 && bit_b == 1)
                {
                    count += 2;
                }
                else
                {
                    count += 1;
                }
            }

            a = a>>1;
            b = b>>1;
            c = c>>1;
        }

        return count;
    }
};