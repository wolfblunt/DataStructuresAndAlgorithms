// Fruit Into Baskets - O(N)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int left = 0, right = 0;
        int maxlen = 0;
        unordered_map<int, int> um;

        while(right<n)
        {
            um[fruits[right]]++;

            if(um.size() <= 2)
            {
                maxlen = max(maxlen, right-left+1);
            }
            else
            {
                um[fruits[left]]--;
                if(um[fruits[left]] == 0)
                {
                    um.erase(fruits[left]);
                }
                left++;
            }

            right++;
        }

        return maxlen;
    }
};