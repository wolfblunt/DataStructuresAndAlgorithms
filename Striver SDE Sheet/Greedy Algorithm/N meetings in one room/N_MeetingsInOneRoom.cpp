// N meetings in one room

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({start[i],end[i]});
    }
    
    sort(v.begin(), v.end(), cmp);
    int ansend = v[0].second;
    int count = 1;
    for(int i=1;i<n;i++)
    {
        if(v[i].first > ansend)
        {
            count++;
            ansend = v[i].second;
        }
    }
    
    return count;
}