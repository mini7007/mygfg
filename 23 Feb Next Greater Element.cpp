class Solution {
    public:
        vector<int> nextLargerElement(vector<int>& arr) {
            stack<int> s;
            for (int i = arr.size() - 1; i >= 0; i--) {
                int val = arr[i];
                while (!s.empty() && s.top() <= val) s.pop();
                arr[i] = s.empty() ? -1 : s.top();
                s.push(val);
            }
            return arr;
        }
    };