import java.util.*;
import java.lang.*;
import java.io.*;

class ArrayReverse {
	public static void main (String[] args) {
	    Scanner s = new Scanner(System.in);
	    int t = s.nextInt();
	    for(int i=0;i<t;i++)
	    {
	        int n = s.nextInt();
	        int[] arr = new int[n];
	        for(int j=0;j<n;j++)
	        {
	            arr[j] = s.nextInt();
	        }
	        
	        for(int j=0;j<n/2;j++)
	        {
	           int temp = arr[j];
	           arr[j] = arr[n-j-1];
	           arr[n-j-1] = temp;
	        }
	        
	        for(int j=0;j<n;j++)
	        {
	            System.out.print(arr[j]+" ");
	        }
	        System.out.println();
	    }
	}
}