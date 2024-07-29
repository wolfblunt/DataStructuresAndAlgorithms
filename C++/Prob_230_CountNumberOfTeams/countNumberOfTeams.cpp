// Count Number of Teams - O(n2)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        for(int i=1;i<n;i++)
        {
            int leftSmall = 0, leftLarge = 0;
            int rightSmall = 0, rightLarge = 0;

            // Left Part of Pivot 'i'
            for(int j=0;j<i;j++)
            {
                if(rating[j] < rating[i])
                {
                    leftSmall++;
                }
                if(rating[j] > rating[i])
                {
                    leftLarge++;
                }
            }

            // Right Part of Pivot 'i'
            for(int j=i+1;j<n;j++)
            {
                if(rating[j] < rating[i])
                {
                    rightSmall++;
                }
                if(rating[j] > rating[i])
                {
                    rightLarge++;
                }
            }

            // Total Combinations -> (leftElement -> Pivot -> RightElement)
            // means total leftElements and rightElements combination for the given pivot
            teams += leftSmall * rightLarge + leftLarge * rightSmall;
        }

        return teams;
    }
};