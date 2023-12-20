// Selection Sort

class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n;i++)
       {
           int iMin = i;
           for(int j=i+1;j<n;j++)
           {
               if(arr[j] < arr[iMin])
               {
                   iMin = j;
               }
           }
           if(iMin != i)
           {
               int temp = arr[iMin];
               arr[iMin] = arr[i];
               arr[i] = temp;
           }
       }
    }
};