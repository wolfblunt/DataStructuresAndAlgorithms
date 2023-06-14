// Find Nth root of M

int NthRoot(int n, int m)
{
    if(m==0 || m==1)
        return m;
        
    int low = 1;
    int high = m;
    while(low<=high)
    {
        int mid = (low+high)/2;
        // int temp = pow(mid,n);
        if(pow(mid,n) == m)
        {
            return mid;
        }
        else if(pow(mid,n) < m)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

  return -1;
}  