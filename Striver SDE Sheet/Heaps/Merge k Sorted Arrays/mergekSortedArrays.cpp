// Merge k Sorted Arrays

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                pq.push(arr[i][j]);
            }
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};