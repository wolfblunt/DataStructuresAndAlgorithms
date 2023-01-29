public class QuickSort{
	public static void main(String[] args) {
		int []arr = new int[] {3,5,1,7,6,4,4,44,2};
		QuickSort_main(arr, 0,(arr.length)-1);
		printArray(arr);
	}

	static void QuickSort_main(int[] arr, int low, int high){
		if(low<high){
			int p = partition(arr, low, high);
			QuickSort_main(arr, low, (p-1));
			QuickSort_main(arr, (p+1), high);
		}

	}

	static int partition(int[] arr, int low, int high){
		int i = low-1;
		int pivot = arr[high];
		for(int j=low;j<high;j++){
			if(arr[j] <= pivot){
				i=i+1;
				swap(arr, i, j);
			}
		}
		swap(arr, i+1, high);
		return (i+1);

	}

	static void swap(int[] arr, int a,int b){
		int temp = arr[b];
		arr[b] = arr[a];
		arr[a] = temp;
	}

	static void printArray(int[] arr){
		for(int i=0;i<arr.length;i++){
			System.out.print(arr[i]+" ");
		}
	}
}