class Solution {
public:
    // Here the approach is that we want K max right ? so the max value is equal to the sum of the positive integers and after that it will      
    // decrease. So, for decreasing the numbers, we have to add -ve numbers and minus +ve numbers.
    // Since we have taken abs of the numbers, so we have to subtract only.
    long long kSum(vector<int>& nums, int k) {
        long long sum=0,n=nums.size();
        vector<long long> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>=0)
            sum+=nums[i];   // Max possible sum obtained from numbers
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        ans.push_back(sum); //pushing max val i.e. sum of positive integers
        priority_queue<pair<long long,int>> pq;
        pq.push({sum-nums[0],0});
        while(ans.size()<k){
            auto p=pq.top();
            pq.pop();
            if((p.second+1)<n){
               pq.push({p.first-nums[p.second+1],p.second+1});//Subtract nextIndex
               pq.push({p.first+nums[p.second]-nums[p.second+1],p.second+1});// Subtract nextIndex and add current Index
            }
            ans.push_back(p.first); // add max val
        }
        return ans.back();
    }
};