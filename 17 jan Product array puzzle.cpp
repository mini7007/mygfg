class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size(), product = 1, zeroCount = count(arr.begin(), arr.end(), 0);
        if (zeroCount > 1) return vector<int>(n, 0);
        for (int x : arr) if (x) product *= x;
        for (int i = 0; i < n; i++) arr[i] = zeroCount ? (arr[i] ? 0 : product) : product / arr[i];
        return arr;
    }
};