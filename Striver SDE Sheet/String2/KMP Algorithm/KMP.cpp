// Time Complexity = O(n+m)
#include <bits/stdc++.h>
using namespace std;

// O(m)
void LongestPrefixSumArray(char *pattern, int m, int* lps)
{
	int len = 0;
	lps[len] = 0;

	int i = 1;

	while(i < m)
	{
		if(pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char* text, char* pattern)
{
	int m = strlen(pattern);
	int n = strlen(text);

	int lps[m];

	LongestPrefixSumArray(pattern, m, lps);

	cout<<"lps table : "<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<"pattern[i] : "<<lps[i]<<endl;
	}

	int i = 0;
	int j = 0;

	while((n-i) >= (m-j))
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}

		if(j==m)
		{
			cout<<"\nFound pattern at index "<<i-j;
			j = lps[j-1];
		}
		else if(i<n && pattern[j]!=text[i])
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

// abaabab
int32_t main()
{
	char text[] = "helloaabcdeabfabcam";
	char pattern[] = "abaabab";
	KMPSearch(text, pattern);
	return 0;
}

