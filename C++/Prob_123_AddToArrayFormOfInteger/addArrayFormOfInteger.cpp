// Add to Array-Form of Integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int a = 0;
        for(int i=num.size()-1;i>=0;i--)
        {
            if(k)
            {
                num[i] += k;
                k = num[i] / 10;
                num[i] %= 10;
            }
            else
                break;
        }

        while(k)
        {
            num.insert(num.begin(), k%10);
            k /=10;
        }
        return num;
    }
};