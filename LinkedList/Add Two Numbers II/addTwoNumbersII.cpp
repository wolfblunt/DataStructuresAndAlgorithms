// Add Two Numbers II

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
        stack<int> s1, s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* list = NULL;
        while(!s1.empty() || !s2.empty() || carry)
        {
            int d1 = !s1.empty() ? s1.top() : 0;
            int d2 = !s2.empty() ? s2.top() : 0;
            if(!s1.empty())
                s1.pop();
            if(!s2.empty())
                s2.pop();

            int sum = d1 + d2 + carry;
            int digit = sum%10;
            carry = sum/10;

            ListNode* temp = new ListNode(digit);
            temp->next = list;
            list = temp;
        }

        return list;
    }
};