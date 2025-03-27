class Solution {
  public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        int i = 0, j = 0, cnt = 0, ans = 0, n = a.size();
        while(i < n && j < n)
            a[i] <= d[j] ? (cnt++, ans = max(ans, cnt), i++) : (cnt--, j++);
        return ans;
    }
};
