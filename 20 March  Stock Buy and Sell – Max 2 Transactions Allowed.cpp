class Solution {
    public:
      int maxProfit(vector<int>& a) {
          int b1 = INT_MAX, s1 = 0, b2 = INT_MAX, s2 = 0;
          for (int p : a) {
              b1 = min(b1, p);
              s1 = max(s1, p - b1);
              b2 = min(b2, p - s1);
              s2 = max(s2, p - b2);
          }
          return s2;
      }
  };