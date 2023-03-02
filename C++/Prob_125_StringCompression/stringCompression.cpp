// String Compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int firstPtr=0;
        int secondPtr=0;
        int n = chars.size();
        if(n==1)
        {
            return 1;
        }
        while(firstPtr<n)
        {
            int count=1;
            while(firstPtr<n-1 && chars[firstPtr]==chars[firstPtr+1])
            {
                count++;
                firstPtr++;
            }

            chars[secondPtr++] = chars[firstPtr++];
            if(count>1)
            {
                string countString = to_string(count);
                for(auto a: countString)
                {
                    chars[secondPtr++]=a;
                }
            }
        }
        return secondPtr;
    }
};