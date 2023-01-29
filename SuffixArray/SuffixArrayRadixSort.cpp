/*==================================
 Title: Suffix Array using Radix Sort
 Complexity: O(n.log(n))
 Author : Sudipto Chandra (Dipu)
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
/*------------------------------------------------------------------------------------*/

void print(int k, const char* title);
bool test = false;

const int SIZ = 10000050; // maximum possible size

int n; // text length
char T[SIZ]; // text string
int SA[SIZ], tempSA[SIZ]; // the sorted suffixes
int RA[SIZ], tempRA[SIZ]; // ranks of suffix array
int L[SIZ]; // used in counting sort

inline int getRA(int i)
{
    return (i < n) ? RA[i] : 0;
}

void radix_sort(int k)
{
    mem(L, 0);
    // count frequencies
    for(int i = 0; i < n; ++i)
    {
        L[getRA(i + k)]++;
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
        int& x = L[getRA(SA[i] + k)];
        tempSA[x++] = SA[i];
    }
    // copy tempSA to SA
    for(int i = 0; i < n; ++i)
    {
        SA[i] = tempSA[i];
    }
}
// text must ends with a $
void buildSA()
{
    // initialize
    n = strlen(T);
    T[n++] = '$', T[n] = 0; // append $
    for(int i = 0; i < n; ++i)
    {
        SA[i] = i;
        RA[i] = T[i];
    }
    if(!test) print(1, "Initialized:");

    // algorithm loop
    for(int k = 1; k < n; k <<= 1)
    {
        // sort by k-th ranks
        radix_sort(k);
        radix_sort(0);
        if(!test) print(k, "After sorting:");
        // compute new ranks
        tempRA[SA[0]] = 0;
        for(int i = 1, r = 0; i < n; ++i)
        {
            if(getRA(SA[i-1]) != getRA(SA[i])) {
                r++;
            }
            else if(getRA(SA[i-1]+k) != getRA(SA[i]+k)) {
                r++;
            }
            tempRA[SA[i]] = r;
        }
        for(int i = 0; i < n; ++i)
        {
            RA[i] = tempRA[i];
        }
        if(!test) print(k, "New ranks:");
        if(RA[SA[n - 1]] == n - 1) break;
    }
}

void print(int k, const char* title = "")
{
    if(title[0]) printf("%s\n", title);
    puts("========================================================");
    printf("|  i | SA[i] | RA[SA[i]] | RA[SA[i] +%2d] | tempRA[i]  |\n", k);
    printf("|----|-------|-----------|---------------|------------|\n");
    for(int i = 0; i < n; ++i)
    {
        printf("| %2d | ", i);
        printf(" %3d  | ", SA[i]);
        printf(" %5d    | ", getRA(SA[i]));
        printf(" %7d      | ", getRA(SA[i]+k));
        printf("   %4d    |\n", tempRA[SA[i]]);
    }
    puts("========================================================");
    cin.get();
}

void RUN()
{
    printf("Text: ");
    gets(T);
    buildSA();
}

void TEST()
{
    test = true;
    int values[] = {
        10,
        100,
        1000,
        10000,
        50000,
        100000,
        500000,
        1000000,
        2000000,
        3000000,
        4000000,
        5000000,
        6000000,
        7000000,
        8000000
    };

    int siz = sizeof(values) / sizeof(int);
    double avg_cpi = 0;

    puts("");
    puts("|         n | Runtime(s) |    TPI(ms)   |");
    puts("|----------:|:----------:|:------------:|");

    for(int k = 0; k < siz; ++k)
    {
        int n = values[k];
        for(int i = 0; i < n; ++i)
        {
            if(rand() & 1)
            {
                T[i] = 'A' + (rand() % 26);
            }
            else if(rand() & 1)
            {
                T[i] = 'a' + (rand() % 26);
            }
            else
            {
                T[i] = '0' + (rand() % 10);
            }

        }
        T[n] = 0;

        time_t start = clock();
        buildSA(); // builds the suffix array
        time_t stop = clock();

        double time = (double)(stop - start) / CLOCKS_PER_SEC;
        double cpi = (double)(stop - start) / (n * log2(n));
        printf("| `%7d` |   `%5.3f`  | `%0.8f` |\n", n, time, cpi);

        if(k) avg_cpi += (values[k] - values[k - 1]) * cpi;
        else avg_cpi += values[k] * cpi;
    }
    avg_cpi /= values[siz - 1];

    printf("\n");
    printf("**Average *Time Per Instructions*** = `%.10f ms`\n", avg_cpi);
}

int main()
{
    //RUN();
    TEST();
    return 0;
}


