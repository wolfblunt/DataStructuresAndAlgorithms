public class InsertionSort{
	public static void main(String[] args){
		int []arr = new int[] {4,3,2,1,0,0,3};
		int temp = 0;
		for(int i=1;i<arr.length;i++){
			int j=i;
			while(j>0 && arr[j-1]>arr[j]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
			}
		}

		for(int k=0;k<arr.length;k++){
			System.out.print(arr[k]+" ");
		}
	}
}