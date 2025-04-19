class Solution {
public:
    int maxXor(vector<int>& a) {
        int max_xor = 0, mask = 0;
        unordered_set<int> s;
        for(int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            s.clear();
            int temp = max_xor | (1 << i);
            for(int num : a) {
                int prefix = num & mask;
                if(s.count(temp ^ prefix)) { max_xor = temp; break; }
                s.insert(prefix);
            }
        }
        return max_xor;
    }
};
