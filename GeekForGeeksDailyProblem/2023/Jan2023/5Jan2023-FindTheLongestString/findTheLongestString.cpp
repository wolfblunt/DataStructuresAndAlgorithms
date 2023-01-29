// Find the longest string

#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    string longestString(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_map<string,int> um;
        for(auto a: words)
        {
            um[a]++;
        }
        int size = INT_MIN;
        string answer;
        for(auto a: words)
        {
            int n = a.size();
            string dummy;
            int count=0;
            for(int i=0;i<n;i++)
            {
                dummy+=a[i];
                if(um[dummy])
                {
                    count++;
                }
            }
            if(count==n && n>size)
            {
                size = n;
                answer=a;
            }
        }
        return answer;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}