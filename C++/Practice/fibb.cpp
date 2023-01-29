#include<iostream>
using namespace std;

int main()
{
	int i;
	cout<<"Enter the no : ";
	cin>>i;
	int fib[i+1];
	fib[0]=0;
	fib[1]=1;
	for(int j=2;j<i+1;j++)
	{
		fib[j] = fib[j-1]+fib[j-2];
	}

	cout<<"\nFibonacci series till "<<i;
	for(int k=0;k<i+1;k++)
	{
		cout<<"\nfib["<<k<<"] : "<<fib[k];
	}


}