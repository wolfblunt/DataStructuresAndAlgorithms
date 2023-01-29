/* Given an unsorted array arr[] of size N having both negative and positive integers. 
The task is place all negative element at the end of array without changing the order
of positive element and negative element. */

 // Time Complexity - O(n)
// Space Complexity - O(n)


import java.util.*;
import java.lang.*;
import java.io.*;

class NegativeElementsToEndWithoutChangeOrder {
	public static void main(String[] args)
	{
		int[] arr = {1, -1, 3, 2, -7, -5, 11, 6 };
		int n = arr.length;
		ArrayList<Integer> pos = new ArrayList<Integer>();
		ArrayList<Integer> neg = new ArrayList<Integer>();
		for(int i=0;i<n;i++)
		{
			if(arr[i]<0)
			{
				neg.add(arr[i]);
			}
			else{
				pos.add(arr[i]);
			}
		}

		int a_size=0;
		for(int i=0;i<pos.size();i++)
		{
			arr[a_size] = pos.get(i);
			a_size++;
		}

		for(int i=0;i<neg.size();i++)
		{
			arr[a_size] = neg.get(i);
			a_size++;
		}



		System.out.println("--------------------");

		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		System.out.println("--------------------");
	}
}