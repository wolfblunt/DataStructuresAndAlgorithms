// Reverse Nodes in k-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nextPtr = NULL;
        int i = 0;
        while(temp!=NULL && i<k)
        {
            temp=temp->next;
            i++;
        }
        if(i==k)
        {
            while(curr && i!=0)
            {
                nextPtr = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextPtr;
                i--;
            }

            if(curr)
            {
                head->next = reverseKGroup(nextPtr, k);
            }
            return prev;
        }
        else
        {
            return head;
        }
    }
};