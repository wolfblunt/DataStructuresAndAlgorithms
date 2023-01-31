// Minimum times A has to be repeated such that B is a substring of it

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int isSubstring(string s1, string s2)
    {
        int M = s1.length();
        int N = s2.length();
     
        for (int i = 0; i <= M - N; i++) {
            int j;
     
            for (j = 0; j < N; j++)
            {
                if (s1[i + j] != s2[j])
                {
                    break;
                }
            }
     
            if (j == N)
                return i;
        }
     
        return -1;
    }
    
    int minRepeats(string A, string B) {
        string rep = A;
        int cnt=1;
        while(A.size()<B.size())
        {
            A+=rep;
            cnt++;
        }
       
        if(isSubstring(A,B)!=-1)
            return cnt;
         A+=rep;
         cnt++;
        if(isSubstring(A,B)!=-1)
            return cnt;
        return -1;
    }
};

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}