// Parenthesis Checker

#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string expression)
    {
        int n = expression.size();
        stack<char> s;
        for (int i = 0; i < n; i++) 
        {
			if(expression[i] == ']' || expression[i] == ')' || expression[i] == '}') 
			{
				if(!s.empty() && (expression[i] == ')' && s.top() == '('))
				    s.pop();
				else if(!s.empty() && (expression[i] == ']' && s.top() == '['))
				    s.pop();
				else if(!s.empty() && (expression[i] == '}' && s.top() == '{'))
				    s.pop();
				else
				    return false;
          	}
          	else
          	{
				s.push(expression[i]);
          	}
        }
    
        if(s.empty())
        {
            return true;
        }
        return false;
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}