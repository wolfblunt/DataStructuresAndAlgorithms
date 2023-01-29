#include<iostream>
//#include<string>
using namespace std;

bool is_Palin(string s,int l,int r)
{
	if(l>=r)
	{
		return true;
	}
	if(s[l]!=s[r])
	{
		return false;
	}
	return is_Palin(s,l+1,r-1);
}

int main()
{
	string s = "racecar";
	int r = s.size();
	if(is_Palin(s,0,r-1))
	{
		cout<<"Palindromic String";
	}
	else{
		cout<<"Not a Palindromic string";
	}
	return 0;
}