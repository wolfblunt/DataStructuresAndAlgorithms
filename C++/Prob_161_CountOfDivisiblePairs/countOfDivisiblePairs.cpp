// Count Of Divisible Pairs

#include <bits/stdc++.h> 

int countOfDivisiblePairs(int n, int m){
	int count = 0;
	int x = n/5;
	vector<int> xv(5,x);
	int y = m/5;
	vector<int> yv(5,y);

	n = n%5;
	m = m%5;
	int currX = 1;
	while(n)
	{
		xv[currX]++;
		currX++;
		n--;
	}

	int currY = 1;
	while(m)
	{
		yv[currY]++;
		currY++;
		m--;
	}

	count = xv[0]*yv[0];
	for(int i=1;i<5;i++)
	{
		count += xv[i] * yv[5-i];
	}

	return count;
}