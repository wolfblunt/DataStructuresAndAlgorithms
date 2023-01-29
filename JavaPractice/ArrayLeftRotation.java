// Arrays: Left Rotation

public class ArrayLeftRotation{
	public static void main(String[] args) {
		int[] a = new int[] {1,2,3,4,5};
		int[] b = new int[a.length];
		int d = 3;
		int n= a.length;
		int temp = 0;
        int in = 0;
        
        for(int i=0;i<n;i++){
        	int new_loc = (i+(n-d)) % n;
        	b[new_loc] = a[i];
        }
        for (int i = 0; i < b.length; i++)   
        {  
            System.out.print(b[i]+ " ");  
        }  

	}
}