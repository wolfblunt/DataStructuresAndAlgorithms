// Find the largest subarray having an equal number of 0’s and 1’s
import java.util.HashMap;

class FindLargestSubarray{
	public static void main(String[] args) {
		int[] arr = new int[] {0,0,1,0,1,0,0};
		findLargestSubarrayFunc(arr);
	}

	static void findLargestSubarrayFunc(int[] s)
	{
		int start = 0;
		int end = -1;
		int sum = 0;
		int n = s.length;
		int largeArray = 0;
		int size = 0;
		HashMap<Integer, Integer> map = new HashMap<>();
		for(int i=0;i<n;i++)
		{
			if(s[i] == 0)
			{
				s[i] = -1;
			}
		}

		for(int i=0;i<n;i++)
		{
			sum+=s[i];
			if(map.containsKey(sum))
			{
				size = i- map.get(sum);
				//System.out.println("size: "+size);
				if(size>largeArray)
				{
					largeArray = size;
					start = map.get(sum) + 1;
					end = i;
				}
			}
			else
			{
				map.put(sum,i);
			}
		}
		if(end==-1)
		{
			System.out.print("Not Found");
		}
		else
		{
			System.out.println("Start Index : "+start+" , End Index: "+end);
			System.out.print("Size of largest subarray having an equal number of 0's and 1's : "
				+largeArray);
		}
	}
}