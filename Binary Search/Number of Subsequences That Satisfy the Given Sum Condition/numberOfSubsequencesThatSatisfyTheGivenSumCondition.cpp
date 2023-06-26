// Number of Subsequences That Satisfy the Given Sum Condition

class Solution {
public:
	const int mod = 1e9+7;
	long long powerFunc(long long a, long long n)
	{
			long long res = 1;
			while(n)
			{
					if(n%2 == 1)
					{
							res = (res*a) % mod;
							n = n-1;
					}
					else
					{
							a = (a*a) % mod;
							n = n/2;
					}
			}
			return res % mod;
	}


	int numSubseq(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int n = nums.size();
			int left = 0;
			int right = n-1;
			int result = 0;
			while(left <= right)
			{
					if(nums[left] + nums[right] <= target)
					{
							result = (result + powerFunc(2, right - left)) % mod;
							left++;
					}
					else
					{
							right--;
					}
			}
			return result % mod;
	}
};