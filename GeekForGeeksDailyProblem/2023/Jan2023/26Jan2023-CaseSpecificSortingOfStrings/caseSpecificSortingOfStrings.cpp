// Case-specific Sorting of Strings

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string lower;
        string upper;
        vector<int> pos;
        for(int i=0;i<n;i++)
        {
            char a = str[i];
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                lower.push_back(str[i]);
                pos.push_back(0);
            }
            else
            {
                upper.push_back(str[i]);
                pos.push_back(1);
            }
        }
        
        int length = 0;
        string res;
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int l = 0;
        int u = 0;
        while(length<n)
        {
            if(pos[length]==0)
            {
                res += lower[l++];
            }
            if(pos[length]==1)
            {
                res += upper[u++];
            }
            length++;
        }
        return res;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}