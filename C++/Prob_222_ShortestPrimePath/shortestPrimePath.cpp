// Shortest Prime Path

class Solution{   
public:
    int solve(int Num1,int Num2)
    {   
        vector<int> prime(1e5,1);
        for(int i=2;i*i<1e5;i++)
        {
            if(prime[i])
            {
                for(int j=2*i;j<1e5;j+=i)
                {
                    prime[j] = 0;
                }
            }
        }
        
        unordered_set<int> st;
        for(int i=1000;i<1e5;i++)
        {
            if(prime[i])
            {
                st.insert(i);
            }
        }
        
        queue<pair<int,int>> q;
        q.push({Num1,0});
        while(!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            string num = to_string(node);
            if(node == Num2)
            {
                return dist;
            }
            
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    
                    char temp = num[i];
                    num[i] = '0'+j;
                    int itemp = stoi(num);
                    if(st.find(itemp) != st.end())
                    {
                        st.erase(itemp);
                        if(itemp == Num2)
                        {
                            return dist+1;
                        }
                        q.push({itemp, dist+1});
                    }
                    num[i] = temp;
                }
            }
        }
        
        return -1;
    }
};