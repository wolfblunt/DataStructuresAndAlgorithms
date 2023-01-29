// Program to print the duplicate elements of an array

public class PrintDuplicate{
	public static void main(String[] args){
		int[] arr1 = new int[] {1,2,3,4,1,3,2,1,8,8,8,8,8,8,8,8};
		int[] arr2 = new int[arr1.length];
		int visited = -1;
		for(int i=0;i<arr1.length;i++){
			int count=0;
			for(int j=i+1;j<arr1.length;j++){
				if(arr1[i]==arr1[j] && arr2[j]!=visited){
					count++;
					arr2[j] = visited;
				}
			}
			if(arr2[i]!=visited && count>0){
				System.out.print(arr1[i] + " ");
			}
		}
	}
}