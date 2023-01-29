import java.io.*;
import java.util.*;
class ArrayUnion {
	public static void main (String[] args) {
	    
		int[] a = {1,2,3,4,5};
		int[] b = {1,2,6,7};
		int n = a.length;
		int m = b.length;
		Solution ob=new Solution();
	    System.out.println(ob.doUnion(a,n,b,m));
		
	}
}


class Solution{
    public static int doUnion(int a[], int n, int b[], int m) 
    {
        HashSet<Integer> arr = new HashSet<Integer>();
        
        for(int i=0;i<n;i++)
        {
            arr.add(a[i]);
        }
        
        for(int i=0;i<m;i++)
        {
            arr.add(b[i]);
        }
        
        int size = arr.size();
        return size;
    }
}