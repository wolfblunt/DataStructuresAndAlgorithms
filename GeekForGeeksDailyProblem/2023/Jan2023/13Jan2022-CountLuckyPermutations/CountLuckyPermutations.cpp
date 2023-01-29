// Count Lucky Permutations

#include bitsstdc++.h
using namespace std;

class Solution {
  public
    long long int luckyPermutations(int N, int M, vectorint arr, vectorvectorint graph) {
        vectorvectorlong long int dp(N, vectorlong long int(1N, 0));
        for (int i = 0; i  N; i++) {
            dp[i][1  i] = 1;   
        }
        vectorvectorint adj(N, vectorint(N, 0));
        for (vectorint edge  graph) {
            adj[edge[0] - 1][edge[1] - 1] = 1;
            adj[edge[1] - 1][edge[0] - 1] = 1;
        }
        
         Iterate over each subsetbitmask of nodes
        for (int bitmask = 0; bitmask  (1  N); bitmask++) 
        {
            for (int i = 0; i  N; i++) 
            {
                 If the ith nodes is included in the current bitmasksubset
                if ((bitmask & (1  i))) 
                {
                     Find j, neighbour of i also present in the current subsetbitmask
                    for (int j = 0; j  N; j++) 
                    {
                        if(bitmask & (1j) && adj[arr[j]-1][arr[i]-1] && j!=i)
                        {
                            dp[i][bitmask] += dp[j][bitmask ^ (1  i)];
                        }
                    }
                }
            }
        }
        
        long long int ans = 0;
         Count where all the nodes are included in the subset because that is the answer
        for (int i = 0; i  N; i++) 
        {
            ans += dp[i][(1  N) - 1];            
        }
        return ans;
    }
};

int main() {
    int t;
    cin  t;
    while (t--) {
        int N, M;
        cin  N  M;
        vectorint arr(N);
        vectorvectorint graph(M, vectorint(2));
        for (int i = 0; i  N; i++) {
            cin  arr[i];
        }
        for (int i = 0; i  M; i++) {
            for (int j = 0; j  2; j++) {
                cin  graph[i][j];
            }
        }
        Solution obj;
        cout  obj.luckyPermutations(N, M, arr, graph)  endl;
    }
}