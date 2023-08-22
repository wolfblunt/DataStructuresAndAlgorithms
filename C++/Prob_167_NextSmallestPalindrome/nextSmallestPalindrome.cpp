// Next Smallest Palindrome

class Solution{
public:
    bool checkAllNine(int num[], int n)
    {
        for(int i=0;i<n;i++)
        {
            if(num[i] != 9)
            {
                return false;
            }
        }
        return true;
    }

	vector<int> generateNextPalindrome(int num[], int n) {
	    vector<int> ans;
	    if(checkAllNine(num,n))
	    {
	        ans.push_back(1);
	        for(int i=0;i<n-1;i++)
	        {
	            ans.push_back(0);
	        }
	        ans.push_back(1);
	        return ans;
	    }
	    
	    int mid = n/2;
	    int i = mid-1;
	    int j = n%2 ? mid+1 : mid;
	    
	    int carry = 1;
	    while(i>=0 && num[i] == num[j])
	    {
	        i--;
	        j++;
	    }
	    
	    bool leftSmallerFlag = false;
	    if(i<0 || num[i] < num[j])  // i<o for palindromic Integer Ex - 4 6 4
	    {
	        leftSmallerFlag = true;
	    }
	    
	    while(i>=0)
	    {
	        num[j] = num[i];
	        i--;
	        j++;
	    }
	    
	    if(leftSmallerFlag)
	    {
	        i=mid-1;
	        if(n%2==1)
	        {
	            num[mid] = num[mid] + carry;
	            carry = num[mid]/10;
	            num[mid] = num[mid]%10;
	            j = mid+1;
	        }
	        else
	        {
	            j = mid;
	        }
	        while(i>=0)
	        {
	            num[i] = num[i] + carry;
	            carry = num[i]/10;
	            num[i] = num[i]%10;
	            num[j] = num[i];
	            i--;
	            j++;
	        }
	    }
	    
	    for(int k=0;k<n;k++)
	    {
	        ans.push_back(num[k]);
	    }
	    
	    return ans;
	}

};