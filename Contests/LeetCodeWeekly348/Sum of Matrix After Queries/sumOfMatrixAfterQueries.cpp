// Sum of Matrix After Queries


class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int> rows(n,1);
        vector<int> cols(n,1);
        long long sum=0;
        long long rowRemain = n;
        long long colRemain = n;
        for(int i=queries.size()-1;i>=0;i--)
        {
            int type = queries[i][0];
            int index = queries[i][1];
            int value = queries[i][2];
            if(type == 0)
            {
                if(rows[index])
                {
                    sum += value*colRemain;
                    rowRemain--;
                    rows[index] = 0;
                }
            }
            if(type==1)
            {
                if(cols[index])
                {
                    sum += value*rowRemain;
                    colRemain--;
                    cols[index] = 0;
                }
            }
        }
        
        return sum;
    }
};