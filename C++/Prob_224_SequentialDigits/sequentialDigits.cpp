// Sequential Digits

// Using BFS
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }

        while(!q.empty())
        {
            int num = q.front();
            q.pop();

            if(num <= high && num>=low)
            {
                ans.push_back(num);
            }
            if(num > high)
            {
                break;
            }
            int r = num%10;
            if(r<9)
            {
                q.push(num*10 + (r+1));
            }
        }

        return ans;
    }
};