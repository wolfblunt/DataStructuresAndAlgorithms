// Fruits Into Baskets III : O(nlogn)

class Solution {
public:
    vector<int> segmentTree;

    void buildSegmentTreeRMQ(vector<int>& baskets, int low, int high, int st_index)
    {
        if(low == high)
        {
            segmentTree[st_index] = baskets[low];
            return;
        }
        int mid = low + (high-low)/2;
        buildSegmentTreeRMQ(baskets, low, mid, 2*st_index);
        buildSegmentTreeRMQ(baskets, mid+1, high, 2*st_index+1);
        segmentTree[st_index] = max(segmentTree[2*st_index], segmentTree[2*st_index+1]);
    }

    int findLeftMostBasket(const int& fruit, int low, int high, int st_index)
    {
        if(segmentTree[st_index] < fruit)
        {
            return -1;
        }
        if(low == high)
        {
            segmentTree[st_index] = -1;
            return 1;
        }
        int mid = low + (high-low)/2;
        int val;
        if(segmentTree[2*st_index] >= fruit)
        {
            val = findLeftMostBasket(fruit, low, mid, 2*st_index);
        }
        else
        {
            val = findLeftMostBasket(fruit, mid+1, high, 2*st_index+1);
        }

        segmentTree[st_index] = max(segmentTree[2*st_index], segmentTree[2*st_index+1]);
        return val;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        segmentTree = vector<int>(4*n+1);
        buildSegmentTreeRMQ(baskets, 0, n-1, 1);

        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(findLeftMostBasket(fruits[i], 0, n-1, 1) == -1)
            {
                count++;
            }
        }

        return count;
    }
};