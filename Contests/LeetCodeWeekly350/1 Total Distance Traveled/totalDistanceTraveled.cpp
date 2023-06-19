// Total Distance Traveled

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        for(int i=1;i<=mainTank;i++)
        {
            if(additionalTank!=0 && i%5==0)
            {
                additionalTank--;
                mainTank++;
            }
            ans+=10;
        }

        return ans;
    }
};