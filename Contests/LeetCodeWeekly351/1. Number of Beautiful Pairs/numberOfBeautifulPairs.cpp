// Number of Beautiful Pairs

class Solution {
public:
    int gcdd(int a, int b)
    {
        while(a%b>0)
        {
            int r = a%b;
            a = b;
            b = r;
        }
        return b;
    }
    
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            int a = nums[i];
            while(a>=10)
            {
                a = a / 10;
            }
            for(int j=i+1;j<n;j++)
            {
                int b = nums[j] % 10;
                if(gcdd(a, b) == 1)
                    count++;
            }
        }
        
        return count;
    }
};