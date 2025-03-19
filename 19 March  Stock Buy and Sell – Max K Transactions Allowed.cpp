class Solution {
    public:
      int maxProfit(vector<int>& prices, int k) {
          int n = prices.size();
          if (n == 0 || k == 0) return 0;
          if (2 * k >= n) {
              int profit = 0;
              for (int i = 1; i < n; i++)
                  profit += max(0, prices[i] - prices[i - 1]);
              return profit;
          }
          vector<int> dp(2 * k + 1, INT_MIN);
          dp[0] = 0;
          for (int price : prices)
              for (int j = 1; j <= 2 * k; j++)
                  dp[j] = j % 2 ? max(dp[j], dp[j - 1] - price) : max(dp[j], dp[j - 1] + price);
          return dp[2 * k];
      }
  };