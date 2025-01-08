class Solution {
public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 2; --i)
            for (int l = 0, r = i - 1; l < r; arr[l] + arr[r] > arr[i] ? cnt += r-- - l : ++l);
        return cnt;
    }
};