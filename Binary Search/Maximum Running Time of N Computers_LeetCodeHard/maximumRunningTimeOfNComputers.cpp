// Maximum Running Time of N Computers

class Solution {
public:
    bool isPossible(vector<int>& batteries, int n, long long time)
    {
        int bs = batteries.size();
        long long totalTime = 0;
        for(long long b: batteries)
        {
            if(b < time)
            {
                totalTime += b;
            }
            else
            {
                totalTime += time;
            }
        }
        return (totalTime >= n*time);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int i=0;i<batteries.size();i++)
        {
            sum += batteries[i];
        }

        long long low = 1;
        long long high = sum/n;

        long long ans = 0;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(isPossible(batteries, n, mid))
            {
                low = mid+1;
                ans = mid;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};