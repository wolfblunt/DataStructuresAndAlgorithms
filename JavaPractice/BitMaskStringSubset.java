// Program to find all subsets of a string Using BitMasking

import java.util.*;

public class BitMaskStringSubset{
	static void stringBitmask(String str, int n){
		int total = 1<<n;
		for(int k=1;k<total;k++){
			//System.out.println("Value of k: "+k);
			for(int i=0;i<n;i++){
				if((k & (1<<i))!=0){
					System.out.print(str.charAt(i)+" ");
				}
			}
			System.out.println("");
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the String: ");
		String str = s.nextLine();
		int n = str.length();
		stringBitmask(str, n);
	}
}
