// Insert An Element At Its Bottom In A Given Stack

#include <bits/stdc++.h> 
void helper(stack<int>& myStack, int x)
{
    if(myStack.size() == 0)
    {
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    helper(myStack, x);
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    helper(myStack, x);
    return myStack;
}