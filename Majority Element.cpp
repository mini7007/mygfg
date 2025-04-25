class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate;
        for (int num : arr) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        count = 0;
        for (int num : arr) if (num == candidate) count++;
        return count > arr.size() / 2 ? candidate : -1;
    }
};
