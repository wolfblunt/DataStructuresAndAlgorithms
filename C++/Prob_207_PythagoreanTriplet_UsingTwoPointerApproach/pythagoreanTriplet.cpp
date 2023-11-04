// Pythagorean Triplet  -  Two Pointer Approach

class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    sort(arr, arr+n, greater<int>());
	    for(int i=0;i<n-2;i++)
	    {
	        if(i>=0 && arr[i] != arr[i-1])
	        {
	            int a = arr[i];
    	        int left = i+1;
    	        int right = n-1;
    	        while(left < right)
    	        {
    	            int a2 = a*a;
    	            int b2 = arr[left]*arr[left];
    	            int c2 = arr[right]*arr[right];
    	            int dd = a2+b2;
    	            if(c2 + b2 == a2)
    	            {
    	                return true;
    	            }
    	            else if(c2 + b2 < a2)
    	            {
    	                int t = arr[right];
    	                while(right >=0 && arr[right] == t)
    	                {
    	                    right--;
    	                }
    	            }
    	            else
    	            {
    	                int u = arr[left];
    	                while(left<n && arr[left] == u)
    	                {
    	                    left++;
    	                }
    	            }
    	        }
	        }
	    }
	   
        return false;
	}
};