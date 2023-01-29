// Binary To Decimal

import java.lang.Math;

public class BinaryToDecimal{
	static void binToDec(int a)
	{
		int sum=0, r=0, i=0;
		while(a>0){
			r = a % 10;
			// sum =sum + r*(int)(Math.pow(2, i));
			sum =sum + r*pow_func(2, i);
			a = a/10;
			i++;
		}
		System.out.print("Sum : "+sum);

	}

	static int pow_func(int a, int b){
		int expo = 1;
		for(int i=0; i<b; i++){
			expo = expo*a;
		}
		return expo;
	}

	public static void main(String[] args) {
		int a = 1111111111;
		binToDec(a);
	}
}

