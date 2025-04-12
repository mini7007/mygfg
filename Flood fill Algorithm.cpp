class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& A, int sr, int sc, int nc) {
        int m = A.size(), n = A[0].size(), oc = A[sr][sc];
        if (oc == nc) return A;
        queue<pair<int, int>> q; q.push({sr, sc});
        A[sr][sc] = nc;
        int d[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i+1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && A[nx][ny] == oc) {
                    A[nx][ny] = nc;
                    q.push({nx, ny});
                }
            }
        }
        return A;
    }
};
