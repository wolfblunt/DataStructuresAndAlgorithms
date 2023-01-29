// Palindrome Linked List

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
    ListNode* reverseLinkedList(ListNode* root)
    {
        ListNode* nextPtr = NULL;
        ListNode* prevPtr = NULL;
        ListNode* currPtr = root;
        while(currPtr!=NULL)
        {
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        return prevPtr;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newRoot = reverseLinkedList(slow->next);
        while(newRoot!=NULL)
        {
            if(newRoot->val != head->val)
            {
                return false;
            }
            newRoot = newRoot->next;
            head = head->next;
        }
        return true;
    }
};