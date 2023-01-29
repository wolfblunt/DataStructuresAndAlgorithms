// Reverse a Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevPtr = NULL;
        ListNode* currPtr = head;
        ListNode* nextPtr = NULL;
        while(currPtr!=NULL)
        {
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        return prevPtr;
    }
};