// Number following a pattern

class Solution{   
public:
    string printMinNumberForPattern(string S){
        string d = "1";
        string ans = "";
        int count = 1;
        int n = S.length();
        for(int i=0;i<n;i++)
        {
            if(S[i] == 'D')
            {
                count++;
                d = to_string(count) + d;
            }
            else
            {
                ans += d;
                count++;
                d = to_string(count);
            }
        }
        
        ans += d;
        return ans;
    }
};