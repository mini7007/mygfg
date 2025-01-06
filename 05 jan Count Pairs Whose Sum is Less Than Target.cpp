class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1, ans = 0;

        // Step 2: Two-pointer approach
        while (l < r) {
            if (arr[l] + arr[r] < target) {
                // All pairs with the current `l` and any element between `l+1` and `r`
                ans += (r - l);
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
