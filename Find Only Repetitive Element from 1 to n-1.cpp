class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        int s = a[0], f = a[0];
        do { 
            s = a[s];
            f = a[a[f]];
        } while (s != f);
        f = a[0];
        while (s != f) { 
            s = a[s];
            f = a[f];
        }
        return s;
    }
};
