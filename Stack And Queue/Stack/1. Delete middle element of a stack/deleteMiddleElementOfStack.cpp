// Delete middle element of a stack


#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void helper(stack<int>&inputStack, int size, int count)
    {
       if(count == size/2)
       {
          inputStack.pop();
          return;
       }
       int num = inputStack.top();
       inputStack.pop();
       helper(inputStack, size, count+1);
       inputStack.push(num);
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&inputStack, int sizeOfStack)
    {
        int count = 0;
        helper(inputStack, sizeOfStack, count);
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}