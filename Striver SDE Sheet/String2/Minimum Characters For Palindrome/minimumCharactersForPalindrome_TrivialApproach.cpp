// Minimum Characters For Palindrome

int minCharsforPalindrome(string A) {
	int left = 0;
    int right = A.size() - 1;
    int temp = right;
    int count = 0;
    while(left<right)
    {
        if(A[left] == A[right])
        {
            left++;
            right--;
        }
        else
        {
            left = 0;
            right = --temp;
            count++;
        }
    }
    
    return count;
	
}