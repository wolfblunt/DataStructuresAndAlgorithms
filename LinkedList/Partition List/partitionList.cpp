// Partition List

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforePtr = new ListNode(0);
        ListNode* afterPtr = new ListNode(0);
        ListNode* beforeCurr = beforePtr;
        ListNode* afterCurr = afterPtr;
        while(head)
        {
            if(head->val < x)
            {
                beforeCurr->next = head;
                beforeCurr = beforeCurr->next;
            }
            else
            {
                afterCurr->next = head;
                afterCurr = afterCurr->next;
            }
            head = head->next;
        }

        afterCurr->next = NULL;
        beforeCurr->next = afterPtr->next;

        return beforePtr->next;
    }
};