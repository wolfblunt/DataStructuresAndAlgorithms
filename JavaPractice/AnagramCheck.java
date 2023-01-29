// Java Program to determine whether two strings are the anagram

import java.util.*;

public class AnagramCheck{

	static void swap(char[] s,int a,int b){
		char temp = s[a];
		s[a] = s[b];
		s[b] = temp;
	}

	static void InsertionSort(char[] s){
		for(int i=1; i<s.length;i++){
			int j = i;
			while(j>0 && s[j]<s[j-1]){
				swap(s,j-1,j);
				j--;
			}
		}

		for(int k=0;k<s.length;k++){
			System.out.print(s[k]+" ");
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter string 1: ");
		String str1 = s.nextLine();
		System.out.print("Enter string 2: ");
		String str2 = s.nextLine();
		str1 = str1.toLowerCase();
		str2 = str2.toLowerCase();
		if(str1.length()!=str2.length()){
			System.out.print("Both strings are not anagram");
		}
		else{
			//Converting both the arrays to character array  
            char[] string1 = str1.toCharArray();
            char[] string2 = str2.toCharArray();
            InsertionSort(string1);
            System.out.println();
            InsertionSort(string2);
            int count = 0;
            for(int i=0;i<string1.length;i++){
            	if(string1[i]!=string2[i]){
            		count++;
            		break;
            	}
            }
            System.out.println();
            if(count==0){
            	System.out.print("Both Strings are anagram");
            }
            else{
            	System.out.print("Both strings are not anagram");
            }
		}
	}
}