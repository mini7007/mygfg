class Solution {
    public:
        int editDistance(string& s1, string& s2) {
            int m = s1.size(), n = s2.size();
            vector<int> prev(n + 1), curr(n + 1);
            iota(prev.begin(), prev.end(), 0);
            for (int i = 1; i <= m; i++) {
                curr[0] = i;
                for (int j = 1; j <= n; j++)
                    curr[j] = s1[i-1] == s2[j-1] ? prev[j-1] : 1 + min({prev[j-1], prev[j], curr[j-1]});
                swap(prev, curr);
            }
            return prev[n];
        }
    };