public class MergeSort{
	static void Merge(int[] arr, int low, int mid, int high){
		int n1 = mid-low +1;
		int n2 = high - mid;
		int []a = new int[n1];
		int []b = new int[n2];
		for(int i=0;i<n1;i++){
			a[i] = arr[low + i];
		} 
		for(int z=0;z<n2;z++){
			b[z] = arr[mid + 1 + z];
		}
		int i=0;
		int j=0;
		int k=low;
		while(i<n1 && j<n2){
			if(a[i]<=b[j]){
				arr[k] = a[i];
				i++;
			}
			else{
				arr[k] = b[j];
				j++;
			}
			k++;
		}

		while(i<n1){
			arr[k]=a[i];
			k++;
			i++;
		}

		while(j<n2){
			arr[k]=b[j];
			k++;
			j++;
		}
	}

	static void printArray(int[] arr){
		for(int i=0;i<arr.length;i++){
			System.out.print(arr[i]+ " ");
		}
	}

	static void sort(int[] arr, int low, int high){
		if(low<high){
			int mid = (low+high)/2;
			sort(arr, low, mid);
			sort(arr, mid + 1, high);
			Merge(arr, low, mid, high);
		}
	}

	public static void main(String[] args) {
		int arr[] = { 12, 11, 13, 5,5, 6, 7,11,9 ,12};
		System.out.println("Without Sorting : ");
		printArray(arr);
		System.out.println();
		sort(arr, 0, (arr.length-1));
		System.out.println("After Sorting : ");
		printArray(arr);
	}

}