// Program to find all subsets of a string Using Backtracking

import java.util.*;

public class StringSubset{

	static void subset(String input, String output){
		if(input.length() == 0){
			System.out.print("| "+ output+"| ");
		}
		else{
			String output1 = output;
			String output2 = output;
			output2 = output+input.charAt(0);
			input = input.substring(1);
			subset(input, output1);
			subset(input, output2);
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the String: ");
		String str = s.nextLine();
		subset(str, "");
	}
}