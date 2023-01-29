#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int isNegative = 0;
        double answer = 0;
        int i=0;
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }

        if(s[i]=='-' || s[i]=='+')
        {
            if(s[i]=='-')
            {
                isNegative = 1;
            }
            i++;
        }

        for(;i<s.size();i++)
        {
            if(s[i]<'0' || s[i]>'9')
            {
                break;
            }
            int temp = s[i] - '0';
            answer = answer*10 + temp;
        }

        if(isNegative)
        {
            answer = -answer;
        }

        if(answer < INT_MIN)
        {
            answer = INT_MIN;
        }

        if(answer > INT_MAX)
        {
            answer = INT_MAX;
        }
        // cout<<answer<<endl;
        return answer;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution a;
        int answer = a.myAtoi(s);
        cout<<answer<<endl;
    }
    return 0;
}
