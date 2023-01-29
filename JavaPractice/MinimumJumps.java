//Minimum number of jumps

 /*
 Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.
*/

import java.lang.*;
import java.io.*;
import java.util.*;
class MinimumJumps
 {
	public static void main (String[] args) throws IOException
	 {
        int[] arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
        System.out.println(new Solution().minJumps(arr));
	 }
	 
}


class Solution{
    static int minJumps(int[] arr){
        // Using DP Approach

        // int n = arr.length;
        // int[] dp = new int[n];
        // for(int i=0;i<n;i++)
        // {
        //     dp[i] = Integer.MAX_VALUE;
        // }
        // dp[0] = 0;
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<i;j++)
        //     {
        //         if(dp[j]!=Integer.MAX_VALUE && (arr[j]+j>=i))
        //         {
        //             if(dp[j]+1<dp[i])
        //             {
        //                 dp[i] = dp[j]+1;
        //             }
        //         }
        //     }
        // }
        // if(dp[n-1]!=Integer.MAX_VALUE)
        // {
        //     return dp[n-1];
        // }
        // else{
        //     return -1;
        // }
        

        // Using Greedy Approach
        int maxR = arr[0];
        int step = arr[0];
        int jump = 1;
        int n = arr.length;
        if(n==1 && arr[0]==0)
        {
            return 0;
        }
        else if(n<=1){
            return 1;
        }
        else if(arr[0]==0)
        {
            return -1;
        }
        else{
            for(int i=1;i<n;i++)
            {
                if(i==(n-1))
                {
                    return jump;
                }
                maxR = Math.max(maxR, i+arr[i]);
                step=step-1;
                if(step==0)
                {
                    jump +=1;
                    if(i>=maxR)
                    {
                        return -1;
                    }
                    step = maxR-i;
                }
            }
            return jump;
        }
    }
}