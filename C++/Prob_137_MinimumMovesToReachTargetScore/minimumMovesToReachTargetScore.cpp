// Minimum Moves to Reach Target Score

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(target>1 && maxDoubles)
        {
            if(target%2 == 0)
            {
                target /= 2;
                maxDoubles--;
                moves++;
            }
            else
            {
                target -= 1;
                moves++;
            }
        }

        return moves + (target - 1);
    }
};