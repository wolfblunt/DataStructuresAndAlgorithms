// Job Sequencing Problem

#include<bits/stdc++.h>

static bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[2] > b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = INT_MIN;

    int n = jobs.size();
    for(int i=0;i<n;i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }

    vector<int> jobsSeq(maxDeadline+1, -1);
    int totalProfit = 0;
    int totalJobs = 0;
    for(int i=0;i<n;i++)
    {
        int deadline = jobs[i][1];
        int jobId = jobs[i][0];
        int profit = jobs[i][2];
        for(int k=deadline; k>0; k--)
        {
            if(jobsSeq[k] == -1)
            {
                totalJobs++;
                jobsSeq[k] = jobId;
                totalProfit += profit;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(totalJobs);
    ans.push_back(totalProfit);
    return ans;
}