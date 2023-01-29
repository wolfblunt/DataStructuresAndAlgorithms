// Program to find the length of longest repeating sequence in a string

import java.util.*;

public class LongestRepeatingSequence{
	static int max(int a, int b){
		return (a>b)? a:b;
	}

	static int longestsequence(char[] str1, char[] str2, int m, int n){
		if(m==0  || n==0){
			return 0;
		}
		if(str1[m-1] == str2[n-1] && m!=n){
			return 1 + longestsequence(str1, str2, m-1, n-1);
		}
		else{
			return max(longestsequence(str1, str2, m, n-1), longestsequence(str1, str2, m-1, n));
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the string : ");
		String str = s.nextLine();
		char[] ch1 = str.toCharArray();
		char[] ch2 = str.toCharArray();
		System.out.print(longestsequence(ch1, ch2, str.length(), str.length()));
	}
}