// Trapping Rain Water
// O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int maxRight = 0;
        int maxLeft = 0;
        int n = height.size();
        int right = n-1;
        int left = 0;
        int result = 0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(maxLeft <= height[left])
                {
                    maxLeft = height[left];
                }
                else
                {
                    result += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if(maxRight <= height[right])
                {
                    maxRight = height[right];
                }
                else
                {
                    result += maxRight - height[right];
                }
                right--;
            }
        }

        return result;
    }
};