class Solution {
    public:
        int longestStringChain(vector<string>& words) {
            sort(words.begin(), words.end(), [](const string &a, const string &b) {
                return a.size() < b.size();
            });
            unordered_map<string, int> dp;
            int res = 1;
            for (auto &w : words) {
                dp[w] = 1;
                for (int i = 0; i < w.size(); i++) {
                    string pred = w.substr(0, i) + w.substr(i + 1);
                    if (dp.count(pred)) dp[w] = max(dp[w], dp[pred] + 1);
                }
                res = max(res, dp[w]);
            }
            return res;
        }
    };