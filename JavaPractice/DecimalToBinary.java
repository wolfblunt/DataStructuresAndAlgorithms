// Decimal To Binary Conversion
public class DecimalToBinary{
	static void decToBin(int a)
	{
		if(a==1){
			System.out.print(1);
		}
		else{
			int r = a % 2;
			decToBin(a/2);
			System.out.print(r);
		}
	}

	public static void main(String[] args) {
		int a = 144;
		decToBin(a);
	}
}