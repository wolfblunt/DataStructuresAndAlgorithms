// Asteroid Collision
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            int flag = 0;
            if(asteroids[i]<0)
            {
                while(!s.empty() && s.top()>=0 && abs(s.top()) <= abs(asteroids[i]))
                {
                    if(abs(s.top())==abs(asteroids[i]))
                    {
                        flag = 1;
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                if(s.empty() && flag==0)
                {
                    s.push(asteroids[i]);
                }
                else if(s.top()<0 && flag==0)
                {
                    s.push(asteroids[i]);
                }
            }
            else
            {
                s.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}