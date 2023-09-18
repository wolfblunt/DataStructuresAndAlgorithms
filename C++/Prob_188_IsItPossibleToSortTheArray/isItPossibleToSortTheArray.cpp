// Is it possible to sort the array - O(nlogn)

class Solution {
public:
    
    bool check(int d, int n, vector<int> a)
    {
        map<int, set<int>> mp;  // 0 - [0+d,0+2d,0+3d,...], 1-[1+d,1+2d,1+3d,...]
        vector<int> visited(n, 0);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                continue;
            }
            int index = i;
            while(!visited[index])
            {
                mp[i].insert(index); 
                visited[index] = 1;
                index = (index+d) % n;
            }
        }
        
        for(auto it: mp)
        {
            vector<int> v;
            for(auto b: it.second)
            {
                v.push_back(a[b]);
            }
            sort(v.begin(), v.end());
            int curr=0;
            // rearranging the sorted values in original array
            for(auto b: it.second)
            {
                a[b] = v[curr];
                curr++;
            }
        }
        
        // Checking if become soorted or not
        bool flag=1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
                return 0;
        }
        return 1;
    }

};