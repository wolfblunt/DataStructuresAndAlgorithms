// Java Program to find all the permutations of a string

import java.util.*;

public class PermutationsString{
	static void swap(char[] str, int l, int r){
		char temp = str[l];
		str[l] = str[r]; 
		str[r] = temp; 
	}

	static void permute(char[] str, int l, int r){
		if(l==r){
			System.out.println(str);
		}
		for(int i=l;i<=r;i++){
			swap(str,l,i);
			permute(str, l+1,r);
			swap(str,l,i);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the string: ");
		String str = sc.nextLine();
		char[] charArray = str.toCharArray();
		permute(charArray,0,(str.length())-1);
	}
}
