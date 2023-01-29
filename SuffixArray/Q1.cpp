#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)

int inputString[10000050];
int suffixArray[10000050];
int tempRA[10000050];
int RA[10000050];
int L[10000050];
int tempSA[10000050];

struct suffix
{
	int index; 
	int rank[2];
};


int cmp(struct suffix a, struct suffix b)
{
	int ans;
	if(a.rank[0] == b.rank[0])
	{
		if(a.rank[1] < b.rank[1])
		{
			ans = 1;
		}
		else
		{
			ans = 0;
		}
	}
	else
	{
		if(a.rank[0] < b.rank[0])
		{
			ans = 1;
		}
		else
		{
			ans = 0;
		}
	}

	return ans;
}


int *suffixArrayImplementation(string txt, int n)
{
	struct suffix suffixArrayStruct[n];

	for (int i = 0; i < n; i++)
	{
		suffixArrayStruct[i].index = i;
		suffixArrayStruct[i].rank[0] = txt[i] - 'a';
		suffixArrayStruct[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
	}

	sort(suffixArrayStruct, suffixArrayStruct+n, cmp);

	int ind[n];

	for (int k = 4; k < 2*n; k = k*2)
	{
		int rank = 0;
		int prev_rank = suffixArrayStruct[0].rank[0];
		suffixArrayStruct[0].rank[0] = rank;
		ind[suffixArrayStruct[0].index] = 0;

		for (int i = 1; i < n; i++)
		{
			if (suffixArrayStruct[i].rank[0] == prev_rank && suffixArrayStruct[i].rank[1] == suffixArrayStruct[i-1].rank[1])
			{
				prev_rank = suffixArrayStruct[i].rank[0];
				suffixArrayStruct[i].rank[0] = rank;
			}
			else
			{
				prev_rank = suffixArrayStruct[i].rank[0];
				suffixArrayStruct[i].rank[0] = ++rank;
			}
			ind[suffixArrayStruct[i].index] = i;
		}

		for (int i = 0; i < n; i++)
		{
			int nextindex = suffixArrayStruct[i].index + k/2;
			suffixArrayStruct[i].rank[1] = (nextindex < n) ? suffixArrayStruct[ind[nextindex]].rank[0] : -1;
		}

		sort(suffixArrayStruct, suffixArrayStruct+n, cmp);
	}

	int *suffixArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		suffixArray[i] = suffixArrayStruct[i].index;
	}

	return suffixArray;
}

inline int getRA(int i, int n)
{
    return (i < n) ? RA[i] : 0;
}

void radix_sort(int k, int n)
{
   	memset(L, 0, sizeof(L));
    // count frequencies
    for(int i = 0; i < n; ++i)
    {
        L[getRA(i + k, n)]++;
    }
    // save first index of every characters
    int mx = max(n, 130);
    for(int i = 0, s = 0; i < mx; ++i)
    {
        int x = L[i];
        L[i] = s;
        s += x;
    }
    // build sorted tempSA
    for(int i = 0; i < n; ++i)
    {
        int& x = L[getRA(suffixArray[i] + k,n)];
        tempSA[x++] = suffixArray[i];
    }
    // copy tempSA to suffixArray
    for(int i = 0; i < n; ++i)
    {
        suffixArray[i] = tempSA[i];
    }
}

void buildSA(string T, int n)
{
    // initialize
    n = T.length();
    // T[n++] = '$', 
    T[n] = 0; // append $
    for(int i = 0; i < n; ++i)
    {
        suffixArray[i] = i;
        RA[i] = T[i];
    }
    // if(!test) print(1, "Initialized:");

    // algorithm loop
    for(int k = 1; k < n; k <<= 1)
    {
        // sort by k-th ranks
        radix_sort(k,n);
        radix_sort(0,n);
        // if(!test) print(k, "After sorting:");
        // compute new ranks
        tempRA[suffixArray[0]] = 0;
        for(int i = 1, r = 0; i < n; ++i)
        {
            if(getRA(suffixArray[i-1],n) != getRA(suffixArray[i],n)) {
                r++;
            }
            else if(getRA(suffixArray[i-1]+k,n) != getRA(suffixArray[i]+k,n)) {
                r++;
            }
            tempRA[suffixArray[i]] = r;
        }
        for(int i = 0; i < n; ++i)
        {
            RA[i] = tempRA[i];
        }
        // if(!test) print(k, "New ranks:");
        if(RA[suffixArray[n - 1]] == n - 1) break;
    }
    // cout<<"Using radix Suffix Array"<<endl;
    // for(int i=0;i<n-1;i++)
    // {
    //     cout<<suffixArray[i]<<endl;
    // }
    // cout<<"------"<<endl;
}


int * kasai(int n, int suffixArray[], string s)
{
	int k = 0;
	int *lcp = new int[n];
	int rank[n];

	for(int i=0;i<n;i++)
	{
		rank[suffixArray[i]] = i;
	}

	for(int i=0;i<n;i++, k=(k-1)>0?(k-1):0)
	{
		if(rank[i] == n-1)
		{
			k=0;
			continue;
		}
		int j = suffixArray[rank[i]+1];
		while(i+k<n && j+k<n && s[i+k] == s[j+k])
		{
			k++;
		}
		lcp[rank[i]]=k;
	}
	return lcp;
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
		cout << arr[i] << " ";
	cout << endl;
}



int main()
{
	string T;
	cin>>T;
	// gets(inputString);
	int inputlength = T.length();
	string txt = inputString+inputString;
	strcpy(char_array, s.c_str());
	int n = txt.length();

	// int *suffixArray = suffixArrayImplementation(txt, n);
	buildSA(txt,n);
	// printArr(suffixArray, n);
	// lcp = kasai(n, suffixArray, txt);
	// int maxlen = 0;
	// int lastmaxlength = 0;
	// vector<string> resultSet;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<i<<":"<<lcp[i]<<endl;
	// }
	for(int i=0;i<n;i++)
	{
		if((txt.substr(suffixArray[i])).length() >= inputlength)
		{
			cout<<(txt.substr(suffixArray[i])).substr(0,inputlength)<<endl;
			break;
		}
	}
	// cout<<maxlen;
	// cout<<resultSet[0]<<endl;
	return 0;
}