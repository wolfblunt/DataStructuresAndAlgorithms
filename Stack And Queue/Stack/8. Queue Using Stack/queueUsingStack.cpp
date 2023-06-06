// Queue Using Stack

#include <stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1; // front
    stack<int> s2; // back
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        if(s1.empty() && s2.empty())
            return -1;
        int x = peek();
        s2.pop();
        return x;
    }

    int peek() {
        if(s1.empty() && s2.empty())
            return -1;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};