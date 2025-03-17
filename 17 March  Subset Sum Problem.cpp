class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          vector<bool> dp(sum + 1, false);
          dp[0] = true;
          for (int num : arr)
              for (int j = sum; j >= num; --j)
                  dp[j] = dp[j] || dp[j - num];
          return dp[sum];
      }
  };