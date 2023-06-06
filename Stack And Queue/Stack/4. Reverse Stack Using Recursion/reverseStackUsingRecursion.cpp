// Reverse Stack Using Recursion

void insertAtEnd(stack<int> &s, int n)
{
    if(s.empty())
    {
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtEnd(s, n);
    s.push(num);
}

void reverseStack(stack<int> &s) {
    if(s.empty())
        return;

    int num = s.top();
    s.pop();
    reverseStack(s);
    insertAtEnd(s, num);
}