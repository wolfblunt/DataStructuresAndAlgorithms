import java.util.*;
import java.lang.*;
import java.io.*;

class CyclicallyRotateByOne {
	public static void main(String[] args) throws IOException
	{
	    int[] a = {1,2,3,4,5};
        int n = a.length;
        Compute obj = new Compute();
        obj.rotate(a, n);
        
        StringBuilder output = new StringBuilder();
        for(int i=0;i<n;i++)
            output.append(a[i]+" ");
        System.out.println(output);
	}
}



class Compute {
    
    public void rotate(int arr[], int n)
    {
        int temp;
        for(int i=n-1;i>0;i--)
        {
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
}