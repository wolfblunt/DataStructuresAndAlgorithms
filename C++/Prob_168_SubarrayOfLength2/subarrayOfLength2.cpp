// Subarray of length 2

class Solution
{
    public:
    long long maxSum(int N, vector<int> A)
    {
        long long sum=0;
        long long countNegative=0;
        long long noOfZeros=0;
        long long minContributingElement = -1;

        for(int i=0;i<N;i++)
        {
            long long elementContribution = (i+1)*(1LL)*(N-i);
            elementContribution = elementContribution*(1LL)*A[i];
            sum = sum + abs(elementContribution);
            
            if(A[i] < 0)
            {
                countNegative++;
            }
            
            if(A[i] == 0)
            {
                noOfZeros++;
            }
            
            if(minContributingElement == -1)
            {
                minContributingElement = abs(elementContribution);
            }
            else
            {
                minContributingElement = min(minContributingElement, abs(elementContribution));
            }
        }
        
        if(countNegative % 2 == 0 || noOfZeros > 0)
        {
            return sum;
        }
        return sum - 2*minContributingElement;
    }
};