// Maximize Score
int maximizeScore(vector<int> &arr, int n, int k)
{
    int sum=0;
    int windowSize = n-k;
    int finalSum = 0;
    for(int i=0;i<n;i++)
    {
        if(i<windowSize)
            sum+=arr[i];
        finalSum+=arr[i];
    }
    
    int currSum=sum;
    for(int i=windowSize; i<n;i++)
    {
        currSum=currSum+arr[i]-arr[i-windowSize];
        sum=min(sum, currSum);
    }
    return finalSum-sum;
}