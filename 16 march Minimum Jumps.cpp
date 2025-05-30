class Solution {
    public:
      int minJumps(vector<int>& arr) {
          int n = arr.size(), jumps = 0, farthest = 0, end = 0;
          if (n == 1) return 0;
          for (int i = 0; i < n - 1; i++) {
              farthest = max(farthest, i + arr[i]);
              if (i == end) {
                  jumps++;
                  end = farthest;
                  if (end >= n - 1) return jumps;
              }
          }
          return -1;
      }
  };