// Insertion Sort for Linked List

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/


class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        if(!head_ref || !head_ref->next)
        {
            return head_ref;
        }
        
        Node* currNode = head_ref->next;
        Node* tempNode = head_ref;
        while(currNode)
        {
            while(tempNode!=currNode)
            {
                if(tempNode->data > currNode->data)
                {
                    int d = currNode->data;
                    currNode->data = tempNode->data;
                    tempNode->data = d;
                }
                tempNode = tempNode->next;
            }
            
            tempNode = head_ref;
            currNode = currNode->next;
        }
        
        return head_ref;
    }
    
};