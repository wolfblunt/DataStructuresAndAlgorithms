#include<bits/stdc++.h>
using namespace std;
 
void lcs_table(char* a, char*b, int m, int n)
{
	int lcs[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				lcs[i][j] = 0;
			}
			else if(a[i-1]==b[j-1])
			{
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}

	int index = lcs[m][n];
	char lcs_arr[index + 1];
	lcs_arr[index] = '\0';
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			lcs_arr[index-1] = a[i-1];
			i--;
			j--;
			index--; 
		}
		else if(lcs[i-1][j]>lcs[i][j-1])
		{
			i--;
		}
		else{
			j--;
		}
	}
	cout << "\nLCS of " << a << " and " << b << " is " << lcs_arr;

}

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main()
{
	char a[] = "BBBAB";
	int a_l = strlen(a);
	cout<< a_l;
	char b[a_l];
	int count = 0;
	for(int k=0;k<a_l;k++)
	{	
		b[k]=a[k];
	}
	for(int i=0;i<a_l/2;i++)
	{
		int temp = b[i];
		b[i] = b[a_l-i-1];
		b[a_l-i-1] = temp;
	}
	
	int b_l = strlen(b);
	lcs_table(a,b,a_l,b_l);
	return 0;
}