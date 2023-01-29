// Approach 2

// User function Template for C++

class Solution {
  public:
    int countSetBits(int a)
    {
        int noOfbits = 1;
        while(a & (a-1))
        {
            noOfbits++;
            a = a & (a-1);
        }
        return noOfbits;
    }
    
    int minVal(int a, int b) {
        int a1 = countSetBits(a);
        int b1 = countSetBits(b);
        int ans = a;
        
        if(a1==b1)
        {
            return ans;
        }
        if(a1<b1)
        {
            int index = 0;
            while(a1!=b1)
            {
                if(a%2==0)
                {
                    a1++;
                    ans+=(1<<index);
                }
                index++;
                a = a/2;
            }
        }
        if(a1>b1)
        {
            int index = 0;
            while(a1!=b1)
            {
                if(a%2==1)
                {
                    a1--;
                    ans = ans - (1<<index);
                }
                index++;
                a = a/2;
            }
        }
        return ans;
    }
};

// Approach: 

// Hint :- Count the Set Bit in both & then think how XOR works in binary form of number.

// XOR Working :-

// -> 0^1 = 1; {Key Point}

// -> 0^0 = 0 = 1^1;

// NOTE- More the Set Bit present (i.e 1) at leftmost position , more is the value.

// So,Now our observations, say that if we want to minimize XOR value,then we need to Set or Unset (on our choice) bit from right towards left of a number in Binary form of a number.

// Step 1 :- Count Set Bit in both number (let named a1 in a,b1 in b).

//   --> Initialize a function (named countSetBit) which take a number "n" & return number of set bit present in it.

//   --> run while loop until n>0 & divide each time n by 2.

//   --> if remainder of n by dividing 2 is 1, then increase count.

// Step 2 :- Intialize an "ans" by "a" & Now, we have 3-Case,

//  ==> either a1 is equal to b1,

//  --> In this case we do nothing we take "X" as a1(i.e ans=a1), so that XOR becomes 0.

// ==> either a1 is less then b1,

// --> In this case we need to increase count of set bit a1, (i.e in ans) , which we do from right to left in binary representation of "a" until "a1" not equal to "b1", if bit is Unset(i.e 0) we make it Set and increase "a1" by 1, & increase "ans" by power of 2 for this position.

// ==> either a1 is greater then b1,

// --> Similary, we proceed, but here we need to decrease set bit count "a1", by making Set bit to Unset in "a" from right to left and decrease "a1" by 1, & decrease "ans" by power of 2.

// Step 3 :- return ans.