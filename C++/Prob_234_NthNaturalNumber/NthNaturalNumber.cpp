// Nth Natural Number - O(logn)

class Solution {
  public:
    /*
	    Instead of filtering out each number, why not convert the number from base 10 to base 9? 🤔➡️🔢

	    In base 9, numbers do not contain the digit '9'. 🚫 Here’s what the base 9 sequence looks like:
	    
	    0 ,1, 2, 3, 4, 5, 6, 7 ,8, 10, 11, 12 ,13 ,14 ,15 ,16 ,17 ,18 , 20 ✨
	    
	    These numbers have no occurrence of the digit '9'. 🎯❌
	    
	    So, it's the same as a decimal-to-binary conversion code, just using
	    
	    n /= 9     instead of     n /= 2. 💻🚀
    
    */
    
    long long findNth(long long n) {
        long long base = 1, result = 0;
        while (n > 0)
        {
            result += (n % 9) * base;
            base *= 10;
            n /= 9;
        }
        return result;
    }
};