// Mice and Cheese

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i] = {reward1[i] - reward2[i], i};
        }
        
        sort(v.begin(), v.end(), greater<>());
        
        int totalPoints = 0;
        for(int i=0;i<n;i++)
        {
            int index = v[i].second;
            if(i<k)
            {
                totalPoints += reward1[index];
            }
            else
            {
                totalPoints += reward2[index];
            }
        }
        
        return totalPoints;
    }
};