// Hands of Straights

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        map<int,int> mp;
        for(auto a: hand)
        {
            mp[a]++;
        }
        
        for(auto a: mp)
        {
            if(mp[a.first] > 0)
            {
                for(int i=1;i<groupSize;i++)
                {
                    mp[a.first+i] -= mp[a.first];
                    if(mp[a.first+i]<0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}