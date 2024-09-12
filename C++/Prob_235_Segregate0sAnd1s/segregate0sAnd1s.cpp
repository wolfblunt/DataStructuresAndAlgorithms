// Segregate 0s and 1s

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<high)
        {
            while(arr[low] == 0)
            {
                low++;
            }
            while(arr[high] == 1)
            {
                high--;
            }
            
            if(low<high)
            {
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }
    }
};