// Task Scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26);
        for (char task : tasks)
            f[task - 'A']++;

        sort(f.begin(), f.end());
        int chunk = f[25] - 1;
        int idleSpots = chunk * n;

        for (int i = 24; i >= 0; i--)
            idleSpots -= min(chunk, f[i]);

        return idleSpots < 0 ? tasks.size() : idleSpots + tasks.size();
    }
};