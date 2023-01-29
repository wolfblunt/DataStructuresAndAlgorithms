public class PrintSmallLarge{
	public static void main(String[] args){
		int []arr1 = new int[] {3,-85,2,-1,4};
		int min_n = arr1[0];
		int max_n = arr1[0];
		for(int i=1;i<arr1.length;i++){
			if(arr1[i]>max_n){
				max_n = arr1[i];
			}
			if(arr1[i]<min_n){
				min_n = arr1[i];
			}
		}
		System.out.println("Min : "+min_n+ " Max: "+max_n);
	}
}