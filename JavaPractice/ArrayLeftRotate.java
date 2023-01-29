//Program to left rotate the elements of an array

public class ArrayLeftRotate{
	public static void main(String []args){
		int []arr1 = new int [] {1,2,3,4,5};
		int n = 5;
		int i;
		for(int k=0;k<n;k++){
			int temp = arr1[0];
			for(i=1;i<arr1.length;i++){
				arr1[i-1] = arr1[i];
			}
			arr1[i-1] = temp;
		}
		
		for(int j=0;j<arr1.length;j++){
			System.out.print(arr1[j] + " ");
		}
	}
}