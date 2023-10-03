// Maximum Value of an Ordered Triplet II

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        multiset<int> multi_ordered_set(nums.begin(),nums.end()); 
        multi_ordered_set.erase(multi_ordered_set.find(nums[0]));
        long long ans=0;
        
        int first=nums[0];
        
        for(int i=1;i<n-1;i++)
        { 
            multi_ordered_set.erase(multi_ordered_set.find(nums[i])); 
            int third=(*(--multi_ordered_set.end()));
            long long temp = (first-nums[i]) *1LL * third;
            ans=max(ans, temp); 
            first=max(first,nums[i]);
        } 
        
        return ans;  
    }
};