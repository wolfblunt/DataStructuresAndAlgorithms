// Maximum Points You Can Obtain from Cards - O(n)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;
        int n = cardPoints.size();
        for(int i=0;i<k;i++)
        {
            leftSum += cardPoints[i];
        }
        int maxSum = leftSum;

        int j = n-1;
        for(int i=k-1;i>=0;i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[j];
            maxSum = max(maxSum, leftSum + rightSum);
            j--;
        }

        return maxSum;
    }
};