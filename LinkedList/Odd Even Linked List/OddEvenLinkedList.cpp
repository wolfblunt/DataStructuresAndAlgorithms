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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead=NULL;
        ListNode* oddTail=NULL;
        ListNode* evenHead=NULL;
        ListNode* evenTail=NULL;

        int count=1;
        while(head!=NULL)
        {
            if(count%2==1)
            {
                if(oddHead==NULL && oddTail==NULL)
                {
                    oddHead=head;
                    oddTail=head;
                    head=head->next;
                }
                else
                {
                    oddTail->next=head;
                    oddTail=oddTail->next;
                    head=head->next;
                }
            }
            else
            {
                if(evenHead==NULL && evenTail==NULL)
                {
                    evenHead=head;
                    evenTail=head;
                    head=head->next;
                }
                else
                {
                    evenTail->next=head;
                    evenTail=evenTail->next;
                    head=head->next;
                }
            }
            count++;
        }

        if(oddHead==NULL)
        {
            return evenHead;
        }
        if(evenHead==NULL)
        {
            return oddHead;
        }
        evenTail->next = NULL;
        oddTail->next = evenHead;
        return oddHead;
    }
};