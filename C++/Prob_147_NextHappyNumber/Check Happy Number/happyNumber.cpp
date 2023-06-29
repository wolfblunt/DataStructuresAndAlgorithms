// Happy Number

class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7)
        {
            return true;
        }

        int sum = n;
        int temp = sum;
        while(sum>9)
        {
            sum = 0;
            while(temp>0)
            {
                int r = temp%10;
                sum += r*r;
                temp = temp/10;
            }
            if(sum==1)
            {
                return true;
            }
            temp = sum;
        }

        if(sum == 7)
            return true;

        return false;
    }
};