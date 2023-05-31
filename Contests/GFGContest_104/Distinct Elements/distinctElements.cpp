// Distinct Elements

class Solution{
    public:
    int distinctElements(int n, int K, vector<int> arr){
        sort(arr.begin(), arr.end(), greater<int>());
        unordered_map<int,int> freq;  // freq.count
        for(int i=0;i<n;i++)
        {
            if(freq.find(arr[i] + K) == freq.end())
            {
                freq[arr[i] + K]++;
            }
            else if(freq.find(arr[i]) == freq.end())
            {
                freq[arr[i]]++;
            }
            else
            {
                freq[arr[i]-K]++;
            }
        }
        
        return freq.size();
    }
};