#include<iostream>
using namespace std;

string swap(string s,int x, int y)
{
	char temp = s[x];
	s[x] = s[y];
	s[y] = temp;
	return s;
}

void permute_string(string s, int l, int r)
{
	if(l==r)
	{
		cout<<s<<"\n";
		return;
	}
	for(int i=l;i<r;i++)
	{
		s = swap(s,i,l);
		permute_string(s,l+1,r);
		s = swap(s,i,l);
	}
}

int main()
{
	string s = "abc";
	permute_string(s, 0,s.length());
	return 0;
}