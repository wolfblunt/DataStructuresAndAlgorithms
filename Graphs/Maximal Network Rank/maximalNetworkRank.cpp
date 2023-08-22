// Maximal Network Rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n,0);
        set<pair<int, int>> cityRoads;

        for(auto a: roads)
        {
            inDegree[a[0]]++;
            inDegree[a[1]]++;
            cityRoads.insert({a[0], a[1]});
            cityRoads.insert({a[1], a[0]});
        }

        int maxRank = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rank = inDegree[i] + inDegree[j];
                if(cityRoads.find({i,j}) != cityRoads.end())
                {
                    rank--;
                }
                maxRank = max(maxRank,rank);
            }
        }

        return maxRank;
    }
};