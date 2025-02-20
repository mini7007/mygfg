class Solution {
    public:
        vector<double> getMedian(vector<int>& arr) {
            priority_queue<int> maxHeap;
            priority_queue<int, vector<int>, greater<int>> minHeap;
            vector<double> res;
    
            for (int num : arr) {
                if (maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
                else minHeap.push(num);
    
                if (maxHeap.size() > minHeap.size() + 1) minHeap.push(maxHeap.top()), maxHeap.pop();
                else if (minHeap.size() > maxHeap.size()) maxHeap.push(minHeap.top()), minHeap.pop();
    
                res.push_back(maxHeap.size() > minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0);
            }
            return res;
        }
    };