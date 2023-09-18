// Count Pairs of Points With Distance k

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>, int> um;
        int n = coordinates.size();
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            // finding all possible (x,y) which gives : 
            //c[i][0]^x+c[i][1]^y=k                   (0)
            //Consider above is true , then
            //if , c[i][0]^x=val                      (1)
            //then c[i][1]^y=k-val                    (2)
            
            //We can definitely find all possible values of val (0 to k inclusive) 
            //using a^b=c , then a^c=b
            //from  (1) , we have c[i][0]^val=x;
            //from  (2) , we have c[i][1]^(k-val)=y;
            //so we just need to traverse through all possible values of val to get pairs(x,y) satisfying  eq.(0) 
            for(int j=0;j<=k;j++)
            {
                //using a^b=c , then a^c=b
                int x = j^coordinates[i][0];
                int y = (k-j)^coordinates[i][1];
                ans += um[{x,y}];
            }

            um[{coordinates[i][0], coordinates[i][1]}]++;
        }

        return ans;
    }
};