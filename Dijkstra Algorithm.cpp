
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> g(V);
        for (auto &e : edges) g[e[0]].emplace_back(e[1], e[2]);
        vector<int> d(V, 1e9); d[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, src);
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            if (p.first > d[p.second]) continue;
            for (auto &x : g[p.second])
                if (p.first + x.second < d[x.first])
                    q.emplace(d[x.first] = p.first + x.second, x.first);
        }
        return d;
    }
};
