// Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
       
        int totalNodes = 0;
        while(curr)
        {
            totalNodes++;
            curr = curr->next;
        }
        if(n==totalNodes)
        {
            return head->next;
        }
        curr = head;
        for(int i=0;i<totalNodes-n-1;i++)
        {
            curr = curr->next;
        }
        
        if(curr->next)
        {
            curr->next = curr->next->next;
        }

        return head;
    }
};