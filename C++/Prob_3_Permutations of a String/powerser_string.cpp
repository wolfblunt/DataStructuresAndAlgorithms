#include<iostream>
#include <string>
using namespace std;

void powerset_func(string s,int l, string res)
{
	// cout<<s.size();
	// cout<<"\nl size : "<<l;
	if(l==s.size())
	{
		cout<<res<<"\n";
		return;
	}
	powerset_func(s,l+1,res+s[l]);
	powerset_func(s,l+1,res);
}

int main()
{
	string s = "abc";
	string res;
	powerset_func(s,0,res);
	return 0;
}