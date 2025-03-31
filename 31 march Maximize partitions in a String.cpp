class Solution {
public:
    int maxPartitions(string &s) {
        int ans = 0, end = 0;
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++) 
            last[s[i] - 'a'] = i;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) ans++;
        }
        return ans;
    }
};
