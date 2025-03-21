class Solution {
    public:
      int findMaxSum(vector<int>& arr) {
          int prev2 = 0, prev1 = 0;
          for (int num : arr) {
              int temp = max(prev1, prev2 + num);
              prev2 = prev1;
              prev1 = temp;
          }
          return prev1;
      }
  };