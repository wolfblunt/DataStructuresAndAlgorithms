// Fruits and Baskets

int findMaxFruits(vector<int> &arr, int n) {
    unordered_map<int, int> freq;
    int left = 0;
    int ans = 0;
    for(int right=0;right<n;right++)
    {
        freq[arr[right]]++;

        while(freq.size() > 2)
        {
            freq[arr[left]]--;
            if(freq[arr[left]] == 0)
            {
                freq.erase(arr[left]);
            }
            left++;
        }

        ans = max(ans, right-left+1);
    }

    return ans;
}