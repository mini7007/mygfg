class Solution {
    public:
      int minCostClimbingStairs(vector<int>& cost) {
          int a = cost[0], b = cost[1];
          for (int i = 2; i < cost.size(); i++)
              tie(a, b) = make_tuple(b, cost[i] + min(a, b));
          return min(a, b);
      }
  };