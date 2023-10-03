// 132 Pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third = INT_MIN; // middle element - acts as b

        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            // currentNumber acts as "a"
            // third acts as "b"
            // stack top entry acts as "c"
            int currentNumber = nums[i];
            if (currentNumber < third) return true;
            while (!s.empty() && s.top() < currentNumber) 
            {
                third = s.top();
                s.pop();
            }
            s.push(currentNumber);
        }
        return false;

    }
};