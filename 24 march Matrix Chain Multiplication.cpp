class Solution {
    public:
        int matrixMultiplication(vector<int> &arr) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            for (int len = 2; len < n; len++) {
                for (int i = 1, j = len; j < n; i++, j++) {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++)
                        dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
                }
            }
            return dp[1][n - 1];
        }
    };