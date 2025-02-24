class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          vector<int> span(arr.size());
          stack<int> st;
          
          for (int i = 0; i < arr.size(); i++) {
              while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
              span[i] = st.empty() ? i + 1 : i - st.top();
              st.push(i);
          }
          return span;
      }
  };