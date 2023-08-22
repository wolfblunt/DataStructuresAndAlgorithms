// Maximum sum Rectangle

class Solution {
  public:
    int kadane(vector<int> &v)
    {
    	int sum = 0;
    	int n = v.size();
    	int maxx = INT_MIN;
    	for(int i=0;i<n;i++)
    	{
    		sum += v[i];
    		maxx = max(maxx, sum);
    		if(sum < 0)
    		{
    			sum = 0;
    		}
    	}
    	return maxx;
    }
    
    int maximumSumRectangle(int n, int m, vector<vector<int>> arr) {
        int mx = INT_MIN;
    	for(int i=0;i<n;i++)
    	{
    		vector<int> v(m,0);
    		for(int i1=i;i1<n;i1++)
    		{
    			for(int j=0;j<m;j++)
    			{
    				v[j] += arr[i1][j];
    			}
    			mx = max(mx, kadane(v));
    		}
    	}

    	return mx;
    }
};