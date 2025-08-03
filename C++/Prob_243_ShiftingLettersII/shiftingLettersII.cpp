// Shifting Letters II

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> differenceArray(n,0);
        int m = shifts.size();
        for(int i=0;i<m;i++)
        {
            if(shifts[i][2] == 0)
            {
                differenceArray[shifts[i][0]]-=1;
                if(shifts[i][1]+1 < n)
                {
                    differenceArray[shifts[i][1] + 1]+=1;
                }
            }
            else
            {
                differenceArray[shifts[i][0]]+=1;
                if(shifts[i][1]+1 < n)
                {
                    differenceArray[shifts[i][1]+1]-=1;
                }
            }
        }

        int shift = 0;
        string ans(n, ' ');
        for(int i=0;i<n;i++)
        {
            shift = (shift + differenceArray[i]) % 26;

            if(shift < 26)
            {
                shift += 26;
            }

            ans[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return ans;
    }
};