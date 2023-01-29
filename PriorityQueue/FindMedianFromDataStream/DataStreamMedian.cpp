class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() >= num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        return maxHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */