// Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        for(int i=0;i<numbers.size();i++)
        {
            int t = target - numbers[i];
            int low = i+1;
            int high = numbers.size() - 1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(numbers[mid] == t)
                {
                    answer.push_back(i+1);
                    answer.push_back(mid+1);
                    return answer;
                }
                else if(numbers[mid] > t)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
        }
        return answer;
    }
};