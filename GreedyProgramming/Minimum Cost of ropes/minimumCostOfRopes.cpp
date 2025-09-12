// Minimum Cost of ropes: O(n) for heap construction + O(n log n) for the heap operations

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(auto &a: arr)
        {
            minHeap.push(a);
        }
        
        int cost = 0;
            
        while(minHeap.size()>1)
        {
            int ele1 = minHeap.top();
            minHeap.pop();
            int ele2 = minHeap.top();
            minHeap.pop();
            int sum = ele1 + ele2;
            cost += sum;
            minHeap.push(sum);
        }
        
        return cost;
    }
};