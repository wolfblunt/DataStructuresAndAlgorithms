// leetcode link : https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int t = n+m-2;
        int r = m-1;
        double result = 1;
        for(int i=1;i<=r;i++)
        {
            result = result*(t-r+i)/i;
        }
        return (int)result;
    }
};