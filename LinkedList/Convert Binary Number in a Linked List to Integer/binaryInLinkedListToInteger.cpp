// Convert Binary Number in a Linked List to Integer

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
    int getDecimalValue(ListNode* head) {
        string s;
        while(head!=NULL)
        {
            s+=to_string(head->val);
            head=head->next;
        }
        int n = s.length();
        int j=0;
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=((s[i]-'0')*pow(2,j));
            j++;
        }
        return sum;
    }
};