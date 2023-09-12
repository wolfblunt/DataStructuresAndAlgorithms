// Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts;

        ListNode* temp = head;
        int len = 0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }

        int n = len/k;
        int extraNodes = len % k;
        temp = head;
        for(int i=0;i<k;i++)
        {
            int partSize = n + (extraNodes > 0);
            ListNode* newHead = nullptr;
            ListNode* newTemp = nullptr;

            for(int j=0;j<partSize;j++)
            {
                if(!newHead)
                {
                    newHead = newTemp = temp;
                }
                else
                {
                    newTemp->next = temp;
                    newTemp = newTemp->next;
                }

                if(temp)
                {
                    temp = temp->next;
                }
            }

            if(newTemp)
            {
                newTemp->next = NULL;
            }

            extraNodes = max(extraNodes-1, 0);
            parts.push_back(newHead);
        }

        return parts;
    }
};