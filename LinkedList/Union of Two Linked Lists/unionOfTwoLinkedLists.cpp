// Union of Two Linked Lists

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> s;
        while(head1!=NULL)
        {
            s.insert(head1->data);
            head1 = head1->next;
        }
        
        while(head2!=NULL)
        {
            s.insert(head2->data);
            head2 = head2->next;
        }
        
        struct Node* temp = new struct Node(0);
        head1 = temp;
        int i = 0;
        for(auto a: s)
        {
            temp->data = a;
            if(i == s.size()-1)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = new struct Node(0);
            }
            temp = temp->next;
            i++;
        }
        return head1;
        
    }
};



struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}