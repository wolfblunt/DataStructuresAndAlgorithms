// Allocate Books

bool isBooksAllocated(vector<int>& A, int barrier, int partition)
{
    int allotedStudent = 0;
    int pages = 0;
    
    for(int i=0;i<A.size();i++)
    {
        if(pages + A[i] > barrier)
        {
            allotedStudent += 1;
            pages = A[i];
            if (pages > barrier) 
            {
                return false;
            }
        }
        else
        {
            pages += A[i];
        }
    }
    
    if(allotedStudent < partition)
    {
        return true;
    }
    return false;
}

books(vector<int> &A, int B) {
    int n = A.size();
    if(B > n)
    {
        return -1;
    }
    int low = A[0];
    int high = 0;
    for(int i=0;i<n;i++)
    {
        high = high + A[i];
        low = min(low, A[i]);
    }
    
    while(low<=high)
    {
        int mid = (low+high) >> 1;
        if(isBooksAllocated(A, mid, B))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return low;
}