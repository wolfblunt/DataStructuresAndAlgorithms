// Sort an array of 0s, 1s and 2s | Dutch National Flag problem

import java.io.*;
import java.util.*;

class Solution
{
    public static void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = a.length - 1;
        int temp;
        while(mid<=high)
        {
            switch(a[mid])
            {
                case 0:{
                    temp = a[mid];
                    a[mid] = a[low];
                    a[low] = temp;
                    low++;
                    mid++;
                    break;
                }
                
                case 1:{
                    mid++;
                    break;
                }
                
                case 2:{
                    temp = a[mid];
                    a[mid] = a[high];
                    a[high] = temp;
                    high--;
                    break;
                }
            }
        }
    }
}


class SortArray012 {
    
    public static void main (String[] args) throws IOException {
        int[] arr = {0,2,1,2,0};
        int n = arr.length;
        Solution ob=new Solution();
        ob.sort012(arr, n);
        StringBuffer str = new StringBuffer();
        for(int i=0; i<n; i++){
            str.append(arr[i]+" ");
        }
        System.out.println(str);
    }
}
