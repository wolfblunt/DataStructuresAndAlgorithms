// Sort a stack Using Recursion

#include <bits/stdc++.h> 

void insertElementInSortedOrder(stack<int>& s, int num)
{
    if(!s.empty() && s.top() <= num)
    {
        s.push(num);
        return;
    }
    if(s.empty())
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    insertElementInSortedOrder(s, num);
    s.push(n);
}

void sortStack(stack<int> &s)
{
	if(s.size() == 1)
    {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    insertElementInSortedOrder(s, num);
}