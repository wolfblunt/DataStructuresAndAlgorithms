// Repeated String Match - Using Rabin karp

class Solution {
public:
    int mod = 1e6;
    int rabinKarp(string source, string target)
    {
        if(source == "" || target == "")
        {
            return -1;
        }

        int m = target.size();
        int power = 1;
        int targetCode = 0;
        for(int i=0;i<m;i++)
        {
            power = (power*31) % mod;
            targetCode = (targetCode*31 + target[i]) % mod;
        }

        int hashCode = 0;
        int n = source.size();
        for(int i=0;i<n;i++)
        {
            hashCode = (hashCode*31 + source[i]) % mod;
            if(i<m-1)
            {
                continue;
            }
            if(i>=m)
            {
                hashCode = (hashCode - source[i-m]*power) % mod; 
            }

            if(hashCode < 0)
            {
                hashCode += mod;
            }

            if(hashCode == targetCode)
            {
                if(source.substr(i-m+1, m) == target)
                {
                    return i-m+1;
                }
            }
        }

        return -1;

    }

    int repeatedStringMatch(string A, string B) {
        int count = 1;
        if(A==B)
        {
            return count;
        }
        string newA = A;
        while(newA.size() < B.size())
        {
            count++;
            newA+=A;
        }

        if(newA==B)
        {
            return count;
        }

        if(rabinKarp(newA, B) != -1)
        {
            return count;
        }
        if(rabinKarp(newA+A, B) != -1)
        {
            return count+1;
        }

        return -1;
    }
};