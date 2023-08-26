// Multiply two strings

class Solution{
  public:
    string addNo(string a, string b)
    {
        int n = a.length() - 1;
        int m = b.length() - 1;
        
        string ans = "";
        int carry = 0;
        while(n>=0 && m>=0)
        {
            int digit = (a[n] - '0') + (b[m] - '0') + carry;
            ans += (digit%10) + '0';
            carry = digit/10;
            n--;
            m--;
        }
        
        while(n>=0)
        {
            int digit = (a[n] - '0') + carry;
            ans += (digit%10) + '0';
            carry = digit/10;
            n--;
        }
        
        while(m>=0)
        {
            int digit = (b[m] - '0') + carry;
            ans += (digit%10) + '0';
            carry = digit/10;
            m--;
        }
        
        if(carry)
        {
            ans += (carry + '0');
        }
        
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            {
                return ans.substr(i);
            }
        }
        
        return "0";
    }
  
    string multiplyNo(string num2, int num1)
    {
        int carry = 0;
        string ans = "";
        int n = num2.length();
        for(int i=n-1; i>=0;i--)
        {
            if(num2[i] == '-')
            {
                continue;
            }
            
            int digit = (num2[i] - '0') * num1 + carry;
            ans += (digit%10) + '0';
            carry = digit/10;
        }
        
        if(carry != 0)
        {
            ans += (carry + '0');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
  
    /*You are required to complete below function */
    string multiplyStrings(string a, string b) {
       string ans = "";
       string zero = "";
       bool aneg = 0, bneg = 0;
       
       for(auto it1: a)
       {
           if(it1 == '-')
           {
               aneg = 1;
               break;
           }
       }
       
       for(auto it2: b)
       {
           if(it2 == '-')
           {
               bneg = 1;
               break;
           }
       }
       
       for(int i = b.length()-1; i>=0; i--)
       {
           if(b[i] == '-')
           {
               continue;
           }
           
           int num1 = b[i] - '0';
           string currMul = multiplyNo(a, num1);
           currMul += zero;
           zero += '0';
           
           ans = addNo(ans, currMul);
       }
       
       if((aneg && bneg) || (!aneg && !bneg))
       {
           return ans;
       }
       
       return '-'+ans;
    }

};