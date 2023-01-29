#include<iostream>
// #include<vector>
// #include<iterator>
// #include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v = {1,2,3,4,5,6};
	vector<int> w = {7,3,4,5,6};
	int v_s = v.size();
	int w_s = w.size();
	//cout<<"Size of v : "<<v_s;
	vector<int>::iterator ptr;

	for(ptr=v.begin();ptr<v.end();ptr++)
	{
		cout<< "Current value of iterator : "<< *ptr << ", ";
		cout <<"\n";
	}
	int match_index;
	int m_size = max(v_s,w_s);
	int diff = abs(v_s-w_s);
	int j=0;
	for(int i=diff;i<m_size;i++)
	{
		if(v[i]==w[j])
		{
			match_index = i;
			break;
		}
		j++;
	}

	cout<< "Match Index  : " << match_index <<" and value is : "<<v[match_index];
}

