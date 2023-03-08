// Koko Eating Bananas

// Time Complexity :- BigO(N * log(M)) where N is no of piles & M is range of K (left to right)

// Space Complexity :- BigO(1) as not using any extra space

class Solution {
public:
    bool canEatInTime(vector<int>& piles, int m, int h)
    {
        long long hours = 0;
        for(auto a: piles)
        {
            long long temp = a/m;
            hours+=temp;
            if(a%m!=0)
            {
                hours++;
            }
        }
        return hours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(canEatInTime(piles, mid, h))
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};