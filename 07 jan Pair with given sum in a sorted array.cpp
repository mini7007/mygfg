class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int num : arr) {
            int complement = target - num;
            if (freq.count(complement)) 
                res += freq[complement];
            
            freq[num]++;
        }

        return res;
    }
};