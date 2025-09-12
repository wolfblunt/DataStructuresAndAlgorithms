/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* helper(Node* p, int num)
    {
        Node* q = p;
        while(p)
        {
            if(p->data == num)
            {
                swap(p->data, q->data);
                q = q->next;
            }
            p = p->next;
        }
        
        return q;
    }
  
    Node* segregate(Node* head) {
        helper(helper(head, 0), 1);
        return head;
    }
};