long long int maxMoney(vector<int>& valueInHouse, vector<long long int>& dp, int n)
{
    if(n==0)
    {
        return valueInHouse[n];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    long long int pick = valueInHouse[n] + maxMoney(valueInHouse, dp, n-2);
    long long int notpick = 0 + maxMoney(valueInHouse, dp, n-1);
    return dp[n]=max(pick, notpick);
}

long long int maxMoneySum(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    //cout<<"\nSize of n in dp: "<<n;
    vector<long long int> dp(n,-1);
    long long int res = maxMoney(valueInHouse, dp, n-1);
    return res;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> t1, t2;
    int n = valueInHouse.size();
    if(n==1)
    {
        return valueInHouse[0];
    }
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            t1.push_back(valueInHouse[i]);
        }
        if(i!=n-1)
        {
            t2.push_back(valueInHouse[i]);
        }
    }

    long long int f1 = maxMoneySum(t1);
    long long int f2 = maxMoneySum(t2);

    return max(f1, f2);
}