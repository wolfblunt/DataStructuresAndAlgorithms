// Find k-th smallest element in given n ranges

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<pair<int,int>> fv;
        // vector<int> v;
        sort(range.begin(), range.end());
        int prev = range[0][0];
        int next = range[0][1];
        fv.push_back({prev, next});
        for(int i=1;i<n;i++)
        {
            if(next>=range[i][0])
            {
                fv.pop_back();
                next = max(next, range[i][1]);
                fv.push_back({prev, next});
            }
            else
            {
                prev = range[i][0];
                next = range[i][1];
                fv.push_back({prev, next});
            }
        }
        
        // for(int j=0;j<fv.size();j++)
        // {
        //     cout<<fv[j].first<<" "<<fv[j].second<<endl;
        // }
        
        vector<int> result;
        for(int i=0;i<q;i++)
        {
            int flag = 0;
            for(int j=0;j<fv.size();j++)
            {
                if(fv[j].second - fv[j].first + 1 < queries[i])
                {
                    queries[i] = queries[i] - (fv[j].second - fv[j].first + 1);
                }
                else
                {
                    flag = 1;
                    result.push_back(fv[j].first + queries[i] - 1);
                    break;
                }
            }
            if(!flag)
            {
                result.push_back(-1);
            }
        }
        
        
        return result;
    } 
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}