class Solution {
public:
    vector<int> jobSequencing(vector<int>& d, vector<int>& p) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < d.size(); ++i) jobs.emplace_back(d[i], p[i]);
        sort(jobs.begin(), jobs.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& job : jobs) {
            if (job.first > pq.size()) pq.push(job.second);
            else if (pq.top() < job.second) pq.pop(), pq.push(job.second);
        }

        int cnt = pq.size(), tot = 0;
        while (!pq.empty()) tot += pq.top(), pq.pop();
        return {cnt, tot};
    }
};
