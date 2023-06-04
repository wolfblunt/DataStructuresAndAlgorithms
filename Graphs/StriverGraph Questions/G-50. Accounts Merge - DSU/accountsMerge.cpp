// Account Merge

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int findUltimateParent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionOp(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv)
            return;
        
        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // [johnsmith@mail.com : 0] 
        // [john_newyork@mail.com : 0]
        // [johnsmith@mail.com : 1] 
        // [john00@mail.com: 1]
        // [mary@mail.com: 2]
        unordered_map<string, int> mapMailNode;  
        int n = accounts.size();
        
        parent.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }
        
        // Mapping the mails and Join the similar mail
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    unionOp(i, mapMailNode[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n]; 
        for(auto a: mapMailNode)
        {
            string mail = a.first;
            int node = findUltimateParent(a.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size() == 0)
            {
                continue;
            }
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto a: mergedMail[i])
            {
                temp.push_back(a);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};