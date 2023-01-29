//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{

  public:

  vector<int> preSmall(vector<int> &arr,int n){
      vector<int> left;
        stack< pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                left.push_back(-1);
            }
            else{
                left.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
      return left;
  }
   
  vector<int> postSmall(vector<int> &arr,int n){
      vector<int> right;
        stack< pair<int,int>> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                right.push_back(n);
            }
            else{
                right.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
      reverse(right.begin(),right.end());
      return right;
  }
   
  //Function to find largest rectangular area possible in a given histogram.
  int getMaxArea(vector<int> &arr, int n)
  {
      // Your code here
      vector<int> left;
      vector<int> right;
      left = preSmall(arr,n);
      right = postSmall(arr,n);
       
        int area;
      for(int i=0;i<n;i++){
            int temp = (right[i]-left[i]-1)*arr[i];
            area = max(area, temp);
      }
    //   cout<<"Ares : "<<area<<endl;
      return area;
  }

    int maxArea(int matrix[MAX][MAX], int m, int n)
    {
        int rect_area=0;
        if(m==0)
            return rect_area;
        vector<int>v(n,0);
        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    v[j]=0;
                }
                else
                {
                    v[j]= v[j]+1;
                }
            }
            rect_area= max(rect_area, getMaxArea(v, v.size()));
        }
        return rect_area;  
    }

};


int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}