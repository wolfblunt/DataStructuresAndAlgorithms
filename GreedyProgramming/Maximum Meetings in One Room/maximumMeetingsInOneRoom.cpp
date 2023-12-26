// Maximum Meetings in One Room

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,int>> finish;
        for(int i=0;i<N;i++)
        {
            finish.push_back({F[i], i+1});
        }
        vector<int> ans;
        
        sort(finish.begin(), finish.end());
        
        ans.push_back(finish[0].second);
        int last = finish[0].first;
        for(int i=1;i<N;i++)
        {
            if(S[finish[i].second -1] > last)
            {
                ans.push_back(finish[i].second);
                last = finish[i].first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};