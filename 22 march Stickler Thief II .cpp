class Solution {
    public:
        int maxValue(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];
    
            auto robRange = [&](int l, int r) {
                int prev2 = 0, prev1 = 0;
                for (int i = l; i <= r; i++) {
                    int curr = max(prev1, prev2 + nums[i]);
                    prev2 = prev1;
                    prev1 = curr;
                }
                return prev1;
            };
    
            return max(robRange(0, n - 2), robRange(1, n - 1));
        }
    };