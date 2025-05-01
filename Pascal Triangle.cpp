class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row(n);
        row[0]=1;
        for(int i=1;i<n;++i) row[i]=row[i-1]*(n-i)/i;
        return row;
    }
};
