class Solution {
  public:
    string findOrder(vector<string> &w) {
        vector<vector<int>> g(26);
        vector<int> in(26), seen(26);
        for (auto &s : w) for (char c : s) seen[c - 'a'] = 1;
        for (int i = 0; i < w.size() - 1; i++) {
            string &a = w[i], &b = w[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return "";
            if (j < n) g[a[j] - 'a'].push_back(b[j] - 'a'), in[b[j] - 'a']++;
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) if (seen[i] && !in[i]) q.push(i);
        string res;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += u + 'a';
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        for (int i = 0; i < 26; i++) if (seen[i] && in[i]) return "";
        return res;
    }
};
