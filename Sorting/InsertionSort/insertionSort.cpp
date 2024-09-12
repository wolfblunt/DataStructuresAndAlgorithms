// Insertion Sort - O(n2)

void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int currentElement = arr[i];
        while(j>=0 && currentElement < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = currentElement;
    }
}