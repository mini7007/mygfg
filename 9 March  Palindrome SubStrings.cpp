class Solution {
    public:
      int countPS(string& s) {
          int n = s.size(), res = 0;
          vector<vector<bool>> dp(n, vector<bool>(n));
          for (int i = n - 1; i >= 0; --i) {
              dp[i][i] = true;
              for (int j = i + 1; j < n; ++j)
                  if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))
                      dp[i][j] = true, res++;
          }
          return res;
      }
  };