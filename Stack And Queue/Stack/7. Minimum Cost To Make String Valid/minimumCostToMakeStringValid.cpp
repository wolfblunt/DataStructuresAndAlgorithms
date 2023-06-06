// Minimum Cost To Make String Valid

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
	int n = str.length();
	if(n%2 == 1)  // odd string is always invalid string
	{
		return -1;
	}

	stack<int> s;
	for(int i=0;i<n;i++)
	{
		if(str[i] == '{')
		{
	  		s.push(str[i]);
		}
		else
		{
			if(!s.empty() && s.top() == '{')
			{
				s.pop();
			}
			else
			{
				s.push(str[i]);
			}
		}
	}

	int a = 0; // count of remaining open brackets
	int b = 0; // count of remaining close brackets
	while(!s.empty())
	{
	    if(s.top() == '}')
	    {
	      	b++;
	    }
	    else
	    {
	      	a++;
	    }
	    s.pop();
	}

	int reversals = (a+1)/2 + (b+1)/2; // no of reversals formula
	return reversals;
}