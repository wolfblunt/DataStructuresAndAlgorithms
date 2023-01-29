public class ElementFrequency{
	public static void main(String []args){
		int [] arr1= new int[]{1,2,3,1,1,1,2,5,6,7,8,8,8,8,8,8,8,2,3};
		int [] arr2 = new int[arr1.length];
		int visited = -1;
		for(int i=0;i<arr1.length;i++){
			int count=1;
			for(int j=i+1;j<arr1.length;j++){
				if(arr1[i]==arr1[j]){
					count++;
					arr2[j] = visited;
				}
			}
			if(arr2[i]!=visited){
				arr2[i] = count;
			}
		}

		for(int j=0;j<arr2.length;j++){
			if(arr2[j]!=visited){
				System.out.println("Element : "+arr1[j]+ " Frequency : "+arr2[j]);
			}
			
		}

	}
}