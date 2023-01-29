// Find the Subarray with the given sum
import java.util.HashMap;
public class SubArraySum{
	public static void main(String[] args) {
		int[] s = new int[] {10,15,-5,15,-10,5};
		int sum = 5;
		subArraySumFunc(s, sum);
	}

	static void subArraySumFunc(int[] s, int sum)
	{
		int start = 0;
		int end = -1;
		int currSum = 0;
		HashMap<Integer, Integer> map = new HashMap<>();
		for(int i=0;i<s.length;i++){
			currSum+=s[i];
			if(currSum-sum==0)
			{
				end = i;
				start = 0;
				break;
			}
			if(map.containsKey(currSum-sum))
			{
				start = map.get(currSum-sum)+1;
				end = i;
				break;
			}
			map.put(currSum, i);
		}
		if(end==-1)
		{
			System.out.print("Not found");
		}
		else
		{
			System.out.println("Start Index: "+start+" & End Index: "+end);
			System.out.print("Subarray : {");
			for(int i=start;i<=end;i++){
				if(i!=end){
					System.out.print(s[i]+", ");
				}
				else{
					System.out.print(s[i]);
				}
				
			}
			System.out.print("}");
		}
	}
}