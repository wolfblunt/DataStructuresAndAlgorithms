// Prime Subtraction Operation: O(N∗Log(Log(N)))

class Solution {
public:
    void sieve(vector<bool> &isPrime, int n)
    {
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i<n;i++)
        {
            for(int j=2*i;j<n;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(1002, true);
        sieve(isPrime, 1002);

        vector<int> primeNo;
        for(int i=0;i<=1002;i++)
        {
            if(isPrime[i])
            {
                primeNo.push_back(i);
            }
        }

        bool flag = false;
        int prev = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < prev)
            {
                prev = nums[i];
                continue;
            }
            flag = true;
            for(int j=0; j<primeNo.size() && primeNo[j] < nums[i]; j++)
            {
                if(nums[i] - primeNo[j] < prev)
                {
                    prev = nums[i] - primeNo[j];
                    flag = false;
                    break;
                }
            }

            if(flag) // if flag value remains same means we didn't find any prime which satisfy the condition
            {
                break;
            }
        }

        return !flag;
    }
};



