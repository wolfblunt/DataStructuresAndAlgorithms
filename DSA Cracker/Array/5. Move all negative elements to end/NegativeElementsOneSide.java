import java.util.*;
import java.lang.*;
import java.io.*;

class NegativeElementsOneSide {
	public static void main(String[] args)
	{
		int[] arr = {1, -1, 3, 2, -7, -5, 11, 6 };
		int n = arr.length;
		int pivot = 0;
		int low = -1;
		int temp;
		for(int i=0;i<n;i++)
		{
			if(arr[i] < pivot)
			{
				low++;
				temp = arr[i];
				arr[i] = arr[low];
				arr[low] = temp;
			}
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