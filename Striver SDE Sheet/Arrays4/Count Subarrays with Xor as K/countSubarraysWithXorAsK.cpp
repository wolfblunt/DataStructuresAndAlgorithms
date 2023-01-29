// Count Subarrays with Xor as K

int Solution::solve(vector<int> &A, int B) {
    map<int, int> freq;
    int xorr = 0;
    int count = 0;
    for(auto a: A)
    {
        xorr = xorr ^ a;
        if(xorr == B)
        {
            count++;
        }
        
        if(freq.find(xorr^B) != freq.end())
        {
            count += freq[xorr^B];
        }
        
        freq[xorr]++;
    }
    return count;
}
