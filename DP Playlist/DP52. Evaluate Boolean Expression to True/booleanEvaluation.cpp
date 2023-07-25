// Boolean Evaluation

#include <bits/stdc++.h> 
const int mod = 1e9+7;
long long helper(string & expression, int i, int j, int isTrue, vector<vector<vector<long long>>> &dp)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        if(isTrue)
        {
            return expression[i] == 'T';
        }
        else
        {
            return expression[i] == 'F';
        }
    }

    if(dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }

    long long ways = 0;
    for(int index=i+1;index<=j-1;index++)
    {
        long long leftTrue = helper(expression, i, index-1, 1, dp);
        long long leftFalse = helper(expression, i, index-1, 0, dp);
        long long rightTrue = helper(expression, index+1, j, 1, dp);
        long long rightFalse = helper(expression, index+1, j, 0, dp);

        if(expression[index] == '&')
        {
            if(isTrue)
            {
                // t&t = t
                ways = (ways + (leftTrue*rightTrue) % mod) % mod;
            }
            else
            {
                // t&f=f ,  f&t=f, f&f=f
                ways = (ways + (leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod + 
                        (leftFalse*rightFalse) % mod) % mod;
            }
        }

        else if(expression[index] == '|')
        {
            if(isTrue)
            {
                // t|t=t, t|f=t, f|t=t
                ways = (ways + (leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod + 
                        (leftTrue*rightTrue) % mod) % mod;
            }
            else
            {
                // f|f=f
                ways = (ways + (leftFalse*rightFalse) % mod) % mod;
            }
        }
        else if(expression[index] == '^')
        {
            if(isTrue)
            {
                // t^f=t, f^t=t
                ways = (ways + (leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod) % mod;
            }
            else
            {
                // t^t=f, f^f=f
                ways = (ways + (leftTrue*rightTrue) % mod + (leftFalse*rightFalse) % mod) % mod;
            }
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & expression) {
    int n = expression.length();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return helper(expression, 0, n-1, 1, dp);
}