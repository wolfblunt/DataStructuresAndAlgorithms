// Reverse both parts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node *reverse(Node *head, int k)
    {
        Node* temp = head;
        int nodes = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            nodes++;
        }
        
        if(head==NULL && head->next==NULL)
            return head;
        
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(curr!=NULL)  // 5->4->3->2->1  Reverse the list
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        Node* h1 = prev;
        Node* h2 = prev->next;
        
        int c=1;
        while(c<nodes-k)
        {
            h1 = h1->next;
            h2 = h2->next;
            c++;
        }
        //h1=3,h2=2
        h1->next = NULL;
        head->next = prev;
        return h2;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}