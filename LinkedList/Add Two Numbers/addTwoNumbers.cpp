// Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* result = temp;
        int carry = 0;
        int sum = 0;
        while(l1 || l2 || carry)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2 = l2->next;
            }
            if(carry!=0)
            {
                sum+=carry;
            }

            carry = sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next = newnode;
            temp = temp->next;
            sum=0;
        }
        return result->next;
    }
};