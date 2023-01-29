// Flip String to Monotone Increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int noOfOnes=0;
        int noOfFlips=0;
        for(auto a: s)
        {
            if(a=='1')
            {
                noOfOnes++;
            }
            else
            {
                noOfFlips++;
            }
            noOfFlips = min(noOfFlips, noOfOnes);
        }
        return noOfFlips;
    }
};