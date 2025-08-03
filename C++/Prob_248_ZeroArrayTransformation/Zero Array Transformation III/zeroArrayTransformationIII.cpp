// Zero Array Transformation III - O(QlogQ + NlogQ)

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> used_query;//Minheap
        priority_queue<int> available_query;//Maxheap
        sort(queries.begin(),queries.end());//Sort queries by start-point  - QlogQ

        //Process all points
        int query_pos = 0;
        int applied_count = 0;

        // NlogQ
        for(int i=0;i<n;++i) 
        {
            //Push all queries starting at i
            while(query_pos<queries.size() and queries[query_pos][0]==i){
                available_query.push(queries[query_pos][1]);
                query_pos++;
            }
            //Previously used_query overlapping with i must be adjusted
            nums[i] -= used_query.size();

            //Apply query if needed
            while(nums[i]>0 and !available_query.empty() and available_query.top()>=i){
                used_query.push(available_query.top());
                available_query.pop();
                nums[i]--;
                applied_count++;
            }
            //If we couldn't manage enough queries
            if(nums[i]>0)   return -1;

            //Remove all queries used and ending at i
            while(!used_query.empty() and used_query.top()==i)
                used_query.pop();
        }
        return queries.size() - applied_count;
    }
};