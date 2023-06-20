// K Radius Subarray Averages - Using Sliding Window
// Time: O(N)
// Space: O(1) extra space

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2*k+1;
        long long windowSum = 0;
        vector<int> result(n, -1);

        if(n < windowSize)  // If the array is too short to cover a window, return all -1s
        {
            return result;
        }

        for(int i=0;i<n;i++)
        {
            windowSum += nums[i];  // push nums[i] into the window

            if(i-windowSize >= 0)
            {
                windowSum -= nums[i-windowSize]; // pop nums[i-windowSize], if any, out of window
            }

            if(i >= windowSize - 1)
            {
                result[i-k] = windowSum / windowSize;  // the center of this window is at `i-k`
            }
        }

        return result;
    }
};