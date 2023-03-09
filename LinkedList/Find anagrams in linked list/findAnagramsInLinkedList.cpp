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