// Reverse alternate nodes in Link List

/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverseNode(Node* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        Node* prevPtr = NULL;
        Node* currPtr = head;
        Node* nextPtr = NULL;
        while(currPtr)
        {
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        
        return prevPtr;
    }
    
    void rearrange(struct Node *odd)
    {
        if(odd == NULL || odd->next==NULL)
        {
            return;
        }
        Node* oddNode = odd;
        Node* evenNode = odd->next;
        Node* oddHead = oddNode;
        Node* evenHead = evenNode;
        while(oddNode->next && evenNode->next)
        {
            oddNode->next = oddNode->next->next;
            oddNode = oddNode->next;
            evenNode->next = evenNode->next->next;
            evenNode = evenNode->next;
        }
        Node* reverseEvenHead = reverseNode(evenHead);
        oddNode->next = reverseEvenHead;
    }
};