class Solution {
public:
    int longestUniqueSubstr(string &s) {
        int lastSeen[128] = {}, maxLength = 0, start = 0;
        for (int end = 0; end < s.size(); ++end) {
            start = max(start, lastSeen[s[end]]);
            lastSeen[s[end]] = end + 1;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};