// Fraction pairs with sum 1

/* 
	Approach

	Try to divide numerator with denominator as much as possible and get the smallest possible value. 
	To make the current fraction as 1 we need to add a number 'x' with the denominator such that numerator + x == denominator.


*/


class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int>mp;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a = numerator[i], b = denominator[i];
            int gcd = __gcd(a, b);
            a /= gcd; b /= gcd;
            int x = b - a;
            ans += mp[{x, b}];
            mp[{a, b}]++;
        }
        return ans;
    }
};