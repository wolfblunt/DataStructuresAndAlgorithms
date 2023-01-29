// Minimize number of Students to be removed

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // int findPosition(int value, vector<int>& lis)
    // {
    //     int low=0;
    //     int high=lis.size()-1;
    //     int mid;
    //     while(low<high)
    //     {
    //         mid = low + (high-low)/2;
    //         if(value==lis[mid])
    //         {
    //             return mid;
    //         }
    //         else if(value<lis[mid])
    //         {
    //             high = mid-1;
    //         }
    //         else
    //         {
    //             low = mid+1;
    //         }
    //     }
    //     return low;
    // }
    
    int removeStudents(int H[], int n) {
        vector<int> increasingSubSequence;
        increasingSubSequence.push_back(H[0]);
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(H[i] > increasingSubSequence[index])
            {
                index++;
                increasingSubSequence.push_back(H[i]);
            }
            else
            {
                //int position = findPosition(H[i], increasingSubSequence);
                int position = lower_bound(increasingSubSequence.begin(),increasingSubSequence.end(),H[i])-increasingSubSequence.begin();
                increasingSubSequence[position] = H[i];
            }
        }
        return n-increasingSubSequence.size();
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}