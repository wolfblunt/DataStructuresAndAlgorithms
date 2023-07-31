// Heap Sort

#include <bits/stdc++.h>
using namespace std;

// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        
        if(leftChild < n && arr[largest] < arr[leftChild])
        {
            largest = leftChild;
        }
        if(rightChild < n && arr[largest] < arr[rightChild])
        {
            largest = rightChild;
        }
        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        int startIdx = (n / 2) - 1;  // Index of last non-leaf node
 
        // Perform reverse level order traversal from last non-leaf node and heapify each node
        for (int i = startIdx; i >= 0; i--) 
        {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for(int i=n-1; i>0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
        
    }
};



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}