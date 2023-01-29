#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s = "bbbbaaabbbb";
	int n = s.length();
	int flag = 1;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1])
		{
			cout<< "Not a substring";
			flag = 0;
			break;
		}
	}
	if(flag)
		cout << "Is a substring";

	return 0;
}