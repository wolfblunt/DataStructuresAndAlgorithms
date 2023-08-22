// Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val)
    {   
        while(head != NULL && head->val == val) // if all the elements are same
        {
            head = head->next;
        }

        if(head == NULL)
            return NULL;
        
        ListNode* pointer;
        pointer = head;

        while (pointer->next != NULL)  // removing from middle of the linked list
        {
            if(pointer->next->val == val)
            {
                pointer->next = pointer->next->next;
            }
            else
            {
                pointer = pointer->next;    
            }
        }
        return head;
    }
};