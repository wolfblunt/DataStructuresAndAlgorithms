// K-th Smallest in Lexicographical Order - O(Log(N)∗Log(K))

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int numbersBeginWith(long long prefix, int n)
    {
        if(prefix > n)
        {
            return 0;
        }
        if(prefix == n)
        {
            return 1;
        }

        long long minPrefix = prefix;
        long long maxPrefix = prefix;
        int count = 1;

        while(1)
        {
            minPrefix = minPrefix*10;
            maxPrefix = maxPrefix*10 + 9;

            if(n < minPrefix)
            {
                break;
            }
            else if(minPrefix <= n && n <= maxPrefix)
            {
                count += (n - minPrefix + 1); 
                break;
            }
            else
            {
                count += (maxPrefix - minPrefix + 1);
            }
        }

        return count;
    }

    int findKthNumber(int n, int k, long long prefix = 0) {
        for(int i = (prefix==0 ? 1 : 0); i <= 9; i++) 
        {
            if(k == 0)
            {
                return prefix;
            }
            int numbers_prefix_i_less_than_n = numbersBeginWith(prefix*10+i, n);
            if(numbers_prefix_i_less_than_n >= k) // if k <= numbers_prefix_i_less_than_n, the answer is begin with the prefix
            {
                return findKthNumber(n, k-1, 10*prefix+i);
            }
            else
            {
                k -= numbers_prefix_i_less_than_n; // if the answer does not begin with the prefix, remove all the numbers begin with this prefix
            }
        }

        return prefix;
    }
};