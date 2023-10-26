// Parallel Courses III

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjacencyList(n+1);
        vector<int> indegree(n+1);

        for(auto a: relations)
        {
            adjacencyList[a[0]].push_back(a[1]);
            indegree[a[1]]++;
        }

        vector<int> waitTime(n+1);
        queue<int> q;
        
        int maxWaitTime = 0;
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                waitTime[i] = time[i-1];
                maxWaitTime = max(maxWaitTime, waitTime[i]);
            }
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(auto a: adjacencyList[curr])
            {
                indegree[a]--;
                waitTime[a] = max(waitTime[curr]+time[a-1], waitTime[a]);
                maxWaitTime = max(maxWaitTime, waitTime[a]);
                if(indegree[a]==0)
                {
                    q.push(a);
                }
            }
        }

        return maxWaitTime;
    }
};