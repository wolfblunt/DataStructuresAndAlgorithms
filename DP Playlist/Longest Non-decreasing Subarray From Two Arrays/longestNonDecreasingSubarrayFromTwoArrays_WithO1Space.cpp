// Longest Non-decreasing Subarray From Two Arrays  -  Using DP with space O(1)

/*

Explanation
dp1 means the maximum step ending with A[i].
dp2 means the maximum step ending with B[i].
Then cosider these 4 transitions:
t11 for A[i - 1] -> A[i]
t12 for A[i - 1] -> B[i]
t21 for B[i - 1] -> A[i]
t22 for B[i - 1] -> B[i]
We update
dp1 = max(t11, t12)
dp2 = max(t12, t22)
res = max(res, dp1, dp2)

Complexity
Time O(n)
Space O(1)


*/

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
        int res = 1, dp1 = 1, dp2 = 1, n = A.size(), t11, t12, t21, t22;
        for (int i = 1; i < n; ++i)
        {
            t11 =  A[i - 1] <= A[i] ? dp1 + 1 : 1;
            t12 = A[i - 1] <= B[i] ? dp1 + 1 : 1;
            t21 = B[i - 1] <= A[i] ? dp2 + 1 : 1;
            t22 = B[i - 1] <= B[i] ? dp2 + 1 : 1;
            dp1 = max(t11, t21);
            dp2 = max(t12, t22);
            res = max(res, max(dp1, dp2));
        }
        return res;
    }
};