public class SecondLargestNumber{
	public static void main(String[] args){
		int []arr = new int[] {30,24,115,17,6,22,31};
		for(int i=0;i<arr.length;i++){
			int jmin = i;
			int temp=0;
			for(int j=i+1;j<arr.length;j++){
				if(arr[j]<arr[jmin]){
					jmin=j;
				}
			}
			if(jmin!=i){
				temp = arr[i];
				arr[i] = arr[jmin];
				arr[jmin] = temp;
			}
		}
		for(int k=0;k<arr.length;k++){
			System.out.print(arr[k]+" ");
		}
		System.out.println("");
		System.out.println("First largest number in array : "+arr[(arr.length)-1]);
		System.out.println("Second largest number in array : "+arr[(arr.length)-2]);
	}
}