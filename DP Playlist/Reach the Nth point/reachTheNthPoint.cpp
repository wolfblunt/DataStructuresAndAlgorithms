// Reach the Nth point

class Solution{
	public:
		int nthPoint(int n){
		    int mod = 1e9+7;
		    if(n==1)
		    {
		        return 1;
		    }
		    if(n==2)
		    {
		        return 2;
		    }
		    int num1 = 1;
		    int num2 = 2;
		    for(int i=3;i<=n;i++)
		    {
		        int temp = (num1%mod+num2%mod)%mod;
		        num1 = num2%mod;
		        num2 = temp%mod;
		    }
		    
		    return num2%mod;
		}
};