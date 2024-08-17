// Minimum Deletions to Make String Balanced - O(N)

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        // vector<int> a(n,0);
        int count_a = 0, count_b = 0;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == 'a')
            {
                count_a++;
            }
        }

        int minDeletion = n;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a')
            {
                count_a--;
            }
            minDeletion = min(minDeletion, count_a + count_b);

            if(s[i] == 'b')
            {
                count_b++;
            }
        }

        return minDeletion;
    }
};