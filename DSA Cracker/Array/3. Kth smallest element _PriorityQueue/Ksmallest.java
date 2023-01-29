import java.io.*;
import java.util.*;
class Ksmallest {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    
		    int arr[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    arr[i]=sc.nextInt();
		    
		    int k=sc.nextInt();
		    Solution ob = new Solution();
		    out.println(ob.kthSmallest(arr, 0, n-1, k));
		}
		out.flush();
	}
}


class Solution{
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    { 
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>(Collections.reverseOrder());  //MaxHeap
        //PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();  //MinHeap =>default
        for(int i=0;i<k;i++)
        {
            pQueue.add(arr[i]);
        }
        for(int i=k;i<arr.length;i++)
        {
            if(pQueue.peek() > arr[i])
            {
                pQueue.remove();
                pQueue.add(arr[i]);
            }
        }
        return pQueue.peek();
    } 
}
