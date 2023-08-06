// Minimum Platforms

int calculateMinPatforms(int arr[], int dep[], int n) {
    sort(arr,arr+n);
    sort(dep,dep+n);
    
    int i=1, j=0;
    int platformNeeded = 1;
    int ans = 1;
    while(i<n && j<n)
    {
        if(arr[i] <= dep[j])
        {
            platformNeeded++;
            i++;
        }
        else if(arr[i] > dep[j])
        {
            platformNeeded--;
            j++;
        }
        
        ans = max(ans, platformNeeded);
    }
    
    return ans;
}