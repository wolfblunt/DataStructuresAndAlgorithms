import java.util.*;
import java.lang.*;
import java.io.*;

//User function Template for Java
class pair  
{  
    long first, second;  
    public pair(long first, long second)  
    {  
        this.first = first;  
        this.second = second;  
    }  
}

class MaxMinArray{
	public static void main(String[] args) throws IOException
	{
	       //  BufferedReader br =
        //     new BufferedReader(new InputStreamReader(System.in));
        // int t =
        //     Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        // while(t-->0)
        // {
        //     long n = Long.parseLong(br.readLine().trim());
        //     long a[] = new long[(int)(n)];
        //     // long getAnswer[] = new long[(int)(n)];
        //     String inputLine[] = br.readLine().trim().split(" ");
        //     for (int i = 0; i < n; i++) {
        //         a[i] = Long.parseLong(inputLine[i]);
        //     }
            
        long[] a = {3, 2, -1, 56, 10000, 167};
        int n = a.length;
        Compute obj = new Compute();
        pair product = obj.getMinMax(a, n); 
        System.out.println(product.first+" "+product.second);
            
	}
}


class Compute 
{
    static pair getMinMax(long a[], long n)  
    {
        long min = Integer.MAX_VALUE;
        long max = Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            if(a[i] < min)
            {
                min = a[i];
            }
            if(a[i] > max)
            {
                max = a[i];
            }
        }
        pair ans = new pair(min, max);
        return ans;
    }
}