// IPO

class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.second < b.second); // sorting based on second field
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        for(int i=0;i<n;i++) 
        {
            projects.push_back({profits[i],capital[i]}); 
        }
        int i=0;
        sort(projects.begin(),projects.end(), cmp);  // sorting based on capital

        priority_queue<int> maxProfit;
        while(k--)
        {
            while(i<n && w>=projects[i].second)
            {
                maxProfit.push(projects[i++].first);
            }
            
            if(!maxProfit.empty())
            {
                w+=maxProfit.top(),maxProfit.pop();
            }
        }
        return w;

    }
};