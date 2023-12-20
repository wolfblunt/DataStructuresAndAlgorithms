// Quick Sort

class Solution
{
    public:
    void swap(int arr[], int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    int partition (int arr[], int low, int high)
    {
       int i = low-1;
       int pivot = arr[high];
       for(int j=low;j<high;j++)
       {
           if(arr[j] <= pivot)
           {
               i=i+1;
               swap(arr, i, j);
           }
       }
       swap(arr, i+1, high);
       return(i+1);
    }
    
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p-1);
            quickSort(arr, p+1, high);
        }
    }
};