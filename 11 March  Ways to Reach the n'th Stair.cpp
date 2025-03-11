class Solution {
    public:
        long long countWays(int n) {
            long long a = 1, b = 1;
            for (int i = 2; i <= n; i++) 
                tie(a, b) = make_tuple(b, a + b);
            return b;
        }
    };