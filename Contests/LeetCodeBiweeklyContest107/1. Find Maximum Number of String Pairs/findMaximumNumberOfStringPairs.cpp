// Find Maximum Number of String Pairs

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0;i<n-1;i++)
        {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            for(int j=i+1;j<n;j++)
            {
                string ss = words[j];
                // cout<<"temp : "<<temp<<" , ss: "<<ss<<endl;
                if(ss == temp)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};