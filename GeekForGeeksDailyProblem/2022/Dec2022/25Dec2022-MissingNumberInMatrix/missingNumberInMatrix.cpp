// Missing Number in Matrix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int a=-1;
        int b=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    a = i;
                    b = j;
                    break;
                }
            }
            if(a!=-1 && b!=-1)
                break;
        }
        // cout<<"a: "<<a<<" b: "<<b<<endl;
        long long int rowSum = 0;
        for(int i=0;i<n;i++)
        {
            if(i!=a)
            {
                for(int j=0;j<m;j++)
                {
                    rowSum += matrix[i][j];
                }
                break;
            }
        }
        // cout<<"rowSum : "<<rowSum<<endl;
        long long int zeroRowSum = 0;
        for(int i=0;i<n;i++)
        {
            if(i==a)
            {
                for(int j=0;j<m;j++)
                {
                    zeroRowSum+=matrix[i][j];
                }
                break;
            }
        }
        
        long long int missingValue = rowSum - zeroRowSum;
        if(missingValue<=0)
            return -1;
        // cout<<"missingValue : "<<missingValue;
        set<long long int>s;
        for(int i=0;i<n;i++)
        {
            long long int col=0;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    col+=missingValue;
                }
                else
                {
                    col+=matrix[i][j];
                }
            }
            s.insert(col);
        }
        
        if(s.size()>1)
            return -1;
        
        long long int dia1=0;
        long long int dia2=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][i]==0)
            {
                dia1+=missingValue;
            }
            else
            {
                dia1+=matrix[i][i];
            }
            
            if(matrix[i][n-i-1]==0)
            {
                dia2+=missingValue;
            }
            else
            {
                dia2+=matrix[i][n-i-1];
            }
        }
        s.insert(dia1);
        s.insert(dia2);
        
        if(s.size()>1)
            return -1;
            
        return missingValue;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}