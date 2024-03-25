// Print N-bit binary numbers having more 1s than 0s - O(2^n)

class Solution{
public:	
    
    void helper(int n, vector<string> &ans, string &s, int zeros, int ones)
    {
        if(s.size() == n)
        {
            ans.push_back(s);
            return;
        }
        
        if(zeros < ones)
        {
            s.push_back('0');
            helper(n, ans, s, zeros+1, ones);
            s.pop_back();
        }
        
        s.push_back('1');
        helper(n, ans, s, zeros, ones+1);
        s.pop_back();
    }
    
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    string s="";
	    int zeros = 0;
	    int ones = 0;
	    helper(n, ans, s, zeros, ones);
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};