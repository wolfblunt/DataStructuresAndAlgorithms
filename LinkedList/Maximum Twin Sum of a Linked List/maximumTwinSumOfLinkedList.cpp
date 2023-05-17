// Maximum Twin Sum of a Linked List

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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maxVal = 0;

        // finding middle element
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *nextNode = NULL;
        ListNode *prev = NULL;

        // reversing the list from the middle
        while(slow!=NULL)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // performing the twin sum operation
        while(prev!=NULL)
        {
            maxVal = max(maxVal, head->val + prev->val);
            prev = prev->next;
            head = head->next;
        }

        return maxVal;
    }
};