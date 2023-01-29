#include<bits/stdc++.h>
using namespace std;
 // using recursion
// int lcs(char* a, char* b, int m,int n)
// {
// 	if(m==0 || n==0)
// 	{
// 		return 0;
// 	}
// 	else if(a[m-1]==b[n-1])
// 	{
// 		return 1 + lcs(a, b, m-1, n-1);
// 	}
// 	else{
// 		return max(lcs(a, b, m, n-1), lcs(a,b, m-1, n));
// 	}
// }

//using tabulation

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

	cout<< "LCS : "<<lcs[m][n];
	cout << "\na: "<<a;
	int index = lcs[m][n];
	cout<< "\nIndex Value : "<<index;
	char lcs_arr[index + 1];
	lcs_arr[index] = '\0';
	int i=m,j=n;
	cout <<"\ni : "<<i<<" j: "<<j;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			lcs_arr[index-1] = a[i-1];
			cout <<"\na data: "<<lcs_arr[index-1]<<"\n";
			i--;
			j--;
			index--; 
			cout<<"\nnew index: "<<index<< "new i : "<<i<< " new j : "<<j;
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
	char a[] = "ABCDGH";
	char b[] = "AEDFHR";
	int a_l = strlen(a);
	int b_l = strlen(b);
	//cout<< "Length of longest common subsequence: "<< lcs(a,b,a_l,b_l);
	lcs_table(a,b,a_l,b_l);
	return 0;
}