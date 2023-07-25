// Remove duplicates from an unsorted linked list

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int, int> um;
        Node *newHead = new Node(-1);
        Node *tail = newHead;
        while(head)
        {
            um[head->data]++;
            if(um[head->data]==1)
            {
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
        }
        tail->next = NULL;
        return newHead->next;
    }
};