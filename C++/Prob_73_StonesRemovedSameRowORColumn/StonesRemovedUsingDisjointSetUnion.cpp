class Solution {
public:
    bool isSame(vector<int> a, vector<int> b)
    {
        if(a[0] == b[0])
        {
            return true;
        }
        if(a[1] == b[1])
        {
            return true;
        }
        return false;
    }

    int findParent(int i, vector<int>& parent)
    {
        if(i==parent[i])
        {
            return i;
        }
        return parent[i] = findParent(parent[i], parent);
    }

    void unionStones(int i, int j, vector<int>& parent, int& connected)
    {
        int i_parent = findParent(i, parent);
        int j_parent = findParent(j, parent);

        if(i_parent!=j_parent)
        {
            connected--;
            parent[j_parent] = i_parent;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int connected=n;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isSame(stones[i], stones[j]))
                {
                    unionStones(i,j,parent,connected);
                }
            }
        }
        int diff = n-connected;
        return diff;
    }
};