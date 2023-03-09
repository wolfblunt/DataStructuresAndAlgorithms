// Find anagrams in linked list

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    bool isAnagram(string a, string b)
    {
        if(a.size()!=b.size())
        {
            return false;
        }
        
        vector<int> ana(26,0);
        for(int i=0;i<a.size();i++)
        {
            ana[a[i] - 'a']++;
            ana[b[i] - 'a']--;
        }
        
        for(auto a: ana)
        {
            if(a!=0)
            {
                return false;
            }
        }
        return true;
    }
    
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*> ans;
        Node* front = head;
        Node* previous = nullptr;
        
        if(!head)
        {
            return ans;
        }
        int n = s.size();
        while(head)
        {
            string anaStr;
            for(int i=0;i<n;i++)
            {
                if(head)
                {
                    anaStr.push_back(head->data);
                    previous = head;
                    head = head->next;
                }
            }
            
            if(isAnagram(anaStr, s))
            {
                ans.push_back(front);
                previous->next = nullptr;
            }
            else
            {
                head = front->next;
            }
            front = head;
        }
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}