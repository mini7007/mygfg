class Solution {
    public:
        int countWays(string &s) {
            if (s[0] == '0') return 0;
            int n = s.size(), prev2 = 1, prev1 = 1;
            for (int i = 1; i < n; i++) {
                int curr = 0;
                if (s[i] != '0') curr = prev1;
                int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (num >= 10 && num <= 26) curr += prev2;
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        }
    };