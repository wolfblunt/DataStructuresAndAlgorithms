// Least Prime Factor

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> answer(n+1);
        
        for(int i=0;i<=n;i++)
        {
            answer[i] = i;
        }
        
        for(int i=2;i<=n;i++)
        {
            if(answer[i] == i)
            {
                for(int j=2*i;j<=n;j+=i)
                {
                    if(answer[j] == j)
                    {
                        answer[j] = i;
                    }
                }
            }
        }
        return answer;
    }
};