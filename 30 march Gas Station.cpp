class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) start = i + 1, curr = 0;
        }
        return total >= 0 ? start : -1;
    }
};
