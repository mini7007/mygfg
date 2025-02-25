class Solution {
    public:
        int getMaxArea(vector<int>& arr) {
            stack<int> s;
            int n = arr.size(), res = 0;
            for (int i = 0; i <= n; i++) {
                while (!s.empty() && (i == n || arr[s.top()] >= arr[i])) {
                    int h = arr[s.top()];
                    s.pop();
                    int w = s.empty() ? i : i - s.top() - 1;
                    res = max(res, h * w);
                }
                s.push(i);
            }
            return res;
        }
    };