// Max sum path in two arrays

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int i = n-1;
        int j = m-1;
        int sumA = 0;
        int sumB = 0;
        while(i>=0 && j>=0)
        {
            if(arr1[i] > arr2[j])
            {
                sumA += arr1[i];
                i--;
            }
            else if(arr1[i] < arr2[j])
            {
                sumB += arr2[j];
                j--;
            }
            else
            {
                sumA = max(sumA,sumB) + arr1[i];
                sumB = sumA;
                i--;
                j--;
            }
        }
        
        while(i>=0)
        {
            sumA += arr1[i];
            i--;
        }
        while(j>=0)
        {
            sumB += arr2[j];
            j--;
        }
        return max(sumA, sumB);
    }
};