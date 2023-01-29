// Program to count the total number of characters in a string

import java.util.*;
public class StringCount{
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		System.out.print("Enter the string : ");
		String str = sc.nextLine();
		int count = 0;
		int p_count = 0;
		for(int i=0;i<str.length();i++){
			if(str.charAt(i)!= ' '){
				count++;
			}
			if(str.charAt(i) == '!' || str.charAt(i) == ',' || str.charAt(i) == '.' ||
				str.charAt(i) == '\'' || str.charAt(i) == '-' || str.charAt(i) == '\"' || str.charAt(i) == '?'
				|| str.charAt(i) == ';' || str.charAt(i) == ')' || str.charAt(i) == ')'){
				p_count++;
			}
		}
		System.out.println("Size of String : "+count);
		System.out.print("Punctuation Count : "+p_count);
	}
}