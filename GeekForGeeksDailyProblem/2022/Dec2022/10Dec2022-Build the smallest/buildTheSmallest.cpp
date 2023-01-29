// Given a number k and string num of digits (0 to 9) denoting a positive integer. 
// Find a string denoting the lowest integer number possible by removing k digits from num, 
// without changing their order.
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}


string buildLowestNumber(string num, int k)
{
    stack<int> st;
    for(int i=0;i<num.length();i++)
    {
        while(!st.empty() && k && st.top()>num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    while(k)
    {
        st.pop();
        k--;
    }
    
    string result = "";
    while(!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    
    while(!result.empty() && result.back()=='0')
    {
        result.pop_back();
    }
    
    if(result.length()==0)
    {
        return "0";
    }
    
    reverse(result.begin(), result.end());
    return result;
}